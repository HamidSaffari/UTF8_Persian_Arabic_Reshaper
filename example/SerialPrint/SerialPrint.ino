/*
  UTF8_Persian_Arabic_Reshaper
  @ Apr 2020 by hamidsaffari@yahoo.com
  Released into the public domain.
  https://github.com/HamidSaffari/UTF8_Persian_Arabic_Reshaper
*/

#include <UTF8_Persian_Arabic_Reshaper.h>

UTF8_Persian_Arabic_Reshaper Reshaper;

void setup() {
  Serial.begin(9600); // open the serial port at 9600 bps:
  
  char txt[] = "سلام دنیا من آردوینو تو ایران هم پیشرفت میکنم";
  
  //String msg1;
  //msg1 = Reshaper.reshape(txt);
  //char *c = (char *)msg1.c_str(); //convert it to char*
  
  Serial.println();
  Serial.println( txt ); // without reshaping.(although PC Serial-reading-software usually reshape that itself,
                         // but in many low level devices like LCD's it is not happening)
  Serial.print( Reshaper.reshape(txt,false) ); // with reshaping. "false" for not reversing the string, defaul is "true".
                                               // if it prints backward then change it to "true".
}

void loop() {

}