/*
  UTF8_Persian_Arabic_Reshaper
  Copyright (C) 2019 Ramin Sangesari
  https://github.com/idreamsi/u8g2-persian-reshaper
  Updated @ Apr 2020 by hamidsaffari@yahoo.com
  https://github.com/HamidSaffari/UTF8_Persian_Arabic_Reshaper 
*/

#include <UTF8_Persian_Arabic_Reshaper.h>

UTF8_Persian_Arabic_Reshaper::UTF8_Persian_Arabic_Reshaper() {
}

UTF8_Persian_Arabic_Reshaper::~UTF8_Persian_Arabic_Reshaper() {
}

//----------------------------------------------------------------------------
bool UTF8_Persian_Arabic_Reshaper::isFromTheSet1(unsigned char ch){
    const unsigned char theSet1[18] = {
        32, '\0', 199, 194, 207, 208, 209, 210,
        184, 168, 191, 40, 41, 46, 33, 44, 58, 248};
    int i = 0;
    while (i < 18)
    {
        if(ch == theSet1[i])
            return true;        
        ++i;
    }
    return false;
}
//----------------------------------------------------------------------------
bool UTF8_Persian_Arabic_Reshaper::isFromTheSet2(unsigned char ch){
    const unsigned char theSet1[10] = {
        32, '\0', 191, 40, 41, 46, 33, 44,
        58, 248 };
    int i = 0;
    while (i < 10)
    {
        if(ch == theSet1[i])
            return true;        
        ++i;
    }
    return false;
}
//----------------------------------------------------------------------------
int UTF8_Persian_Arabic_Reshaper::FindGlyph(unsigned char chFind){
  for (int i = 0; i < N_DISTINCT_CHARACTERS; i++) {
    if (pgm_read_word(&(prForms[i].AsciiCode)) == chFind) {
	return i;
	break;
    }
  }
  return -1;
}
//----------------------------------------------------------------------------
String UTF8_Persian_Arabic_Reshaper::reshape(char *Text, bool reverse_String){
  
  String prBuffer = "";
  int stat = 0;
  unsigned char pLetter = ' ';    	//Previous word
  unsigned char letter;             	//Letter
  unsigned char nLetter;     	      	//Next word
  unsigned char temp;
  
  while(temp = *Text++){
    //is Number ?
    if (temp >= '0' && temp <= '9') {
      //d = temp - '0';
      letter = temp;
    }
    else if(temp >= 128){ 
      letter = *Text++;
      letter += 32;
      temp += 32;
      if(letter == 207){
        if(temp == 218 || temp == 250){ 
          letter = 144; //گ
        }
      }
      else if(letter == 166)
        { 
        if(temp == 218 || temp == 250){ //چ
          letter = 141;
        }
        else
        { 
          letter = 228; //ن
        }
      }
    } 
    else
    {
      letter = temp;
    }
	//
    if(letter == 172)
    {
      if(temp == 248 || temp == 32)
      {
        letter = 44;
      }
    }        
    temp = *Text++;
    if(temp >= 128)
    {
      nLetter = *Text++; 
      nLetter += 32; 
      temp += 32;
      if(nLetter == 207)
      {
        if(temp == 218 || temp == 250)
        { 
          nLetter = 144; //گ
        }
      }
    else if(nLetter == 166)
    {
      if(temp == 218 || temp == 250)
      { //چ
        nLetter = 141; 
      }
      else
      {
        nLetter = 228; //ن
      }
    }
    *Text--;
    *Text--;
    }
    else
    {
      nLetter = temp; 
      *Text--;
    }
	//
    if(nLetter == 172)
    {
      if(temp == 248 || temp == 32)
      {
        nLetter = 44;
      }
    }      
  int isunk = 0; 
	/*
	Final: at the end of the word.
	Medial: at the middle of the word.
	Initial: at the beginning of the word.
	Isolated: the character alone (not part of a word).
	*/
    if (isFromTheSet1(pLetter))
      if (isFromTheSet2(nLetter))
        stat = 0;  //Isolated
      else
        stat = 1;  //Initial
    else
      if (isFromTheSet2(nLetter))
        stat = 2;  //Final
      else
        stat = 3;  //Medial

	int number = FindGlyph(letter);
  
  #ifdef DEBUG
	  Serial.print("Letter code: ");
	  Serial.println(letter);
	  Serial.print("Number is: ");
	  Serial.println(number);
	  Serial.print("Pos: ");
	  Serial.println(stat);
	  Serial.println("--------------");
  #endif

	switch (stat){
		case 0: //Isolated
			prBuffer += (char*)pgm_read_ptr(&(prForms[number].isoGlyph));		
			break;
		case 1: //Initial
			prBuffer += (char*)pgm_read_ptr(&(prForms[number].iniGlyph));
			break;
		case 2: //Final
			prBuffer += (char*)pgm_read_ptr(&(prForms[number].endGlyph));
			break;
		case 3: //Medial
			prBuffer += (char*)pgm_read_ptr(&(prForms[number].midGlyph));
			break;		
		default:
			isunk = 1;
			break;	
	}			  
    if(isunk == 0)
      pLetter = letter;  
  }
  
  if(reverse_String) utf8rev((char *)prBuffer.c_str());
  
  return prBuffer; 
}
//----------------------------------------------------------------------------
// https://stackoverflow.com/questions/199260/how-do-i-reverse-a-utf-8-string-in-place

void UTF8_Persian_Arabic_Reshaper::utf8rev(char *str){
    /* this assumes that str is valid UTF-8 */
    char    *scanl, *scanr, *scanr2, c;
    /* first reverse the string */
    for (scanl = str, scanr = str + strlen(str); scanl < scanr;)
        c = *scanl, *scanl++= *--scanr, *scanr= c;
    /* then scan all bytes and reverse each multibyte character */
    for (scanl = scanr = str; c = *scanr++;) {
        if ( (c & 0x80) == 0) // ASCII char
            scanl = scanr;
        else if ( (c & 0xc0) == 0xc0 ) { // start of multibyte
            scanr2 = scanr;
            switch (scanr - scanl) {
                case 4: c = *scanl, *scanl++= *--scanr, *scanr = c; // fallthrough
                case 3: // fallthrough
                case 2: c = *scanl, *scanl++= *--scanr, *scanr = c;
            }
            scanr = scanl = scanr2;
        }
    }
}
//----------------------------------------------------------------------------
//UTF-8 strlen function
int UTF8_Persian_Arabic_Reshaper::strlen_utf8(char *s) {
   int i = 0, j = 0;
   while (s[i]) {
     if ((s[i] & 0xc0) != 0x80) j++;
     i++;
   }
   return j;
}