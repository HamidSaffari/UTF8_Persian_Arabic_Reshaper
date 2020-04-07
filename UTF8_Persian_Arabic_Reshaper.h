/*
  UTF8_Persian_Arabic_Reshaper
  Copyright (C) 2019 Ramin Sangesari
  https://github.com/idreamsi/u8g2-persian-reshaper
  Updated @ Apr 2020 by hamidsaffari@yahoo.com
  https://github.com/HamidSaffari/UTF8_Persian_Arabic_Reshaper
*/

#ifndef UTF8_PERSIAN_ARABIC_RESHAPER_H
#define UTF8_PERSIAN_ARABIC_RESHAPER_H


#if defined(ARDUINO) && ARDUINO >= 100
    #include "Arduino.h"
#elif defined(ENERGIA) // LaunchPad, FraunchPad and StellarPad specific
    #include "Energia.h"
#elif defined(RPI) // Raspberry Pi
    #define RaspberryPi
#elif defined(SPARK)
    #include "application.h"
#else
    #include "WProgram.h"
#endif

//----------------------------------------------------------------------------

//#define DEBUG

//----------------------------------------------------------------------------


class UTF8_Persian_Arabic_Reshaper
{
	
public:
  UTF8_Persian_Arabic_Reshaper();
  virtual ~UTF8_Persian_Arabic_Reshaper();
  
  String reshape(char *Text, bool reverse_String =true);
  void utf8rev(char *str);
  int strlen_utf8(char *s);
  
private:

  int FindGlyph(unsigned char chFind);
  bool isFromTheSet1(unsigned char ch);
  bool isFromTheSet2(unsigned char ch);
  
};



typedef struct prGlyph {
  int AsciiCode;
  char* codeGlyph;
  char* isoGlyph;
  char* iniGlyph;
  char* midGlyph;
  char* endGlyph;
};

const prGlyph prForms[] PROGMEM = {
    // Ascii Code, Code, Isolated, Initial, Medial, Final
    {193, "\u0621", "\uFE80", "\uFE80", "\uFE80", "\uFE80" },     //1 HAMZA ء	[*]
    {194, "\u0622", "\uFE81", "\uFE81", "\uFE82", "\uFE82" },     //2 ALEF_MADDA آ [*]
    {195, "\u0623", "\uFE83", "\uFE83", "\uFE84", "\uFE84" },     //3 ALEF_HAMZA_ABOVE أ [*]
    {196, "\u0624", "\uFE85", "\uFE85", "\uFE86", "\uFE86" },     //4 WAW_HAMZA ؤ [*]
    {197, "\u0625", "\uFE87", "\uFE87", "\uFE88", "\uFE88" },     //5 ALEF_HAMZA_BELOW إ [*]
    {198, "\u0626", "\uFE89", "\uFE8B", "\uFE8C", "\uFE8A" },     //6 YEH_HAMZA ئ [*]
    {199, "\u0627", "\uFE8D", "\uFE8D", "\uFE8E", "\uFE8E" },     //7 ALEF ا [*]
    {200, "\u0628", "\uFE8F", "\uFE91", "\uFE92", "\uFE90" },     //8 BEH ب
    {555, "\u0629", "\uFE93", "\uFE93", "\uFE94", "\uFE94" },     //9 TEH_MARBUTA ة [*]
    {202, "\u062A", "\uFE95", "\uFE97", "\uFE98", "\uFE96" }, 	  //10 TEH ت
    {203, "\u062B", "\uFE99", "\uFE9B", "\uFE9C", "\uFE9A" }, 	  //11 THEH ث
    {204, "\u062C", "\uFE9D", "\uFE9F", "\uFEA0", "\uFE9E" }, 	  //12 JEEM ج
    {205, "\u062D", "\uFEA1", "\uFEA3", "\uFEA4", "\uFEA2" }, 	  //13 HAH ح
    {206, "\u062E", "\uFEA5", "\uFEA7", "\uFEA8", "\uFEA6" }, 	  //14 KHAH خ
    {207, "\u062F", "\uFEA9", "\uFEA9", "\uFEAA", "\uFEAA" },     //15 DAL د [*]
    {208, "\u0630", "\uFEAB", "\uFEAB", "\uFEAC", "\uFEAC" },     //16 THAL ذ [*]
    {209, "\u0631", "\uFEAD", "\uFEAD", "\uFEAE", "\uFEAE" },     //17 REH ر [*]
    {210, "\u0632", "\uFEAF", "\uFEAF", "\uFEB0", "\uFEB0" },     //18 ZAIN ز [*]
    {184, "\u0698", "\uFB8A", "\uFB8A", "\uFB8B", "\uFB8B" },     //19 ZHEH ژ [*]
    {211, "\u0633", "\uFEB1", "\uFEB3", "\uFEB4", "\uFEB2" }, 	  //20 SEEN 
    {212, "\u0634", "\uFEB5", "\uFEB7", "\uFEB8", "\uFEB6" }, 	  //21 SHEEN 
    {213, "\u0635", "\uFEB9", "\uFEBB", "\uFEBC", "\uFEBA" }, 	  //22 SAD ص
    {214, "\u0636", "\uFEBD", "\uFEBF", "\uFEC0", "\uFEBE" }, 	  //23 DAD ض
    {215, "\u0637", "\uFEC1", "\uFEC3", "\uFEC4", "\uFEC2" }, 	  //24 TAH ط
    {216, "\u0638", "\uFEC5", "\uFEC7", "\uFEC8", "\uFEC6" }, 	  //25 ZAH ظ
    {217, "\u0639", "\uFEC9", "\uFECB", "\uFECC", "\uFECA" }, 	  //26 AIN ع
    {218, "\u063A", "\uFECD", "\uFECF", "\uFED0", "\uFECE" }, 	  //27 GHAIN غ
    {160, "\u0640", "\u0640", "\u0640", "\u0640", "\u0640" },     //28 TATWEEL ـ
    {161, "\u0641", "\uFED1", "\uFED3", "\uFED4", "\uFED2" }, 	  //29 FEH ف
    {162, "\u0642", "\uFED5", "\uFED7", "\uFED8", "\uFED6" }, 	  //30 QAF ق
    {163, "\u0643", "\uFED9", "\uFEDB", "\uFEDC", "\uFEDA" },     //31 KAF Arabic ك
    {164, "\u0644", "\uFEDD", "\uFEDF", "\uFEE0", "\uFEDE" }, 	  //32 LAM ل
    {165, "\u0645", "\uFEE1", "\uFEE3", "\uFEE4", "\uFEE2" }, 	  //33 MEEM م
    {228, "\u0646", "\uFEE5", "\uFEE7", "\uFEE8", "\uFEE6" }, 	  //34 NOON ن
    {167, "\u0647", "\uFEE9", "\uFEEB", "\uFEEC", "\uFEEA" }, 	  //35 HEH ه
    {168, "\u0648", "\uFEED", "\uFEED", "\uFEEE", "\uFEEE" },     //36 WAW و [*]
    {169, "\u0649", "\uFEEF", "\uFEEF", "\uFEF0", "\uFEF0" },     //37 ALEF_MAKSURA [*]
    {170, "\u064A", "\uFEF1", "\uFEF3", "\uFEF4", "\uFEF2" },  	  //38 YEH Arabic ي 
    {172, "\u06CC", "\uFBFC", "\uFBFE", "\uFBFF", "\uFBFD" }, 	  //39 YEH Farsi ی
    {141, "\u0686", "\uFB7A", "\uFB7C", "\uFB7D", "\uFB7B" }, 	  //40 CHEH چ
    {222, "\u067E", "\uFB56", "\uFB58", "\uFB59", "\uFB57" }, 	  //41 Peh پ
    {144, "\u06AF", "\uFB92", "\uFB94", "\uFB95", "\uFB93" }, 	  //42 Gaf گ
    {201, "\u06A9", "\uFB8E", "\uFB90", "\uFB91", "\uFB8F" },  	  //43 Kaf ک
    {32, "\u0020", "\u0020", "\u0020", "\u0020", "\u0020" },      //44 Space
    {44, "\u060C", "\u060C", "\u060C", "\u060C", "\u060C" },	  //45 Kama
    {20, "\u200C", "\u200C", "\u200C", "\u200C","\u200C" }, 	  //46 half-space
    {58, "\u003A", "\u003A", "\u003A", "\u003A", "\u003A" },      //47 :
    {187, "\u061B", "\u061B", "\u061B", "\u061B", "\u061B" },     //48 ؛
    {46, "\u002E", "\u002E", "\u002E", "\u002E", "\u002E" },      //49 .
    {191, "\u061F", "\u061F", "\u061F", "\u061F", "\u061F" },     //50 ؟
    {48, "\u06F0", "\u06F0", "\u06F0", "\u06F0", "\u06F0" },      //51 0
    {49, "\u06F1", "\u06F1", "\u06F1", "\u06F1", "\u06F1" },      //52 1
    {50, "\u06F2", "\u06F2", "\u06F2", "\u06F2", "\u06F2" },      //53 2
    {51, "\u06F3", "\u06F3", "\u06F3", "\u06F3", "\u06F3" },      //54 3
    {52, "\u06F4", "\u06F4", "\u06F4", "\u06F4", "\u06F4" },      //55 4
    {53, "\u06F5", "\u06F5", "\u06F5", "\u06F5", "\u06F5" },      //56 5
    {54, "\u06F6", "\u06F6", "\u06F6", "\u06F6", "\u06F6" },      //57 6
    {55, "\u06F7", "\u06F7", "\u06F7", "\u06F7", "\u06F7" },      //58 7
    {56, "\u06F8", "\u06F8", "\u06F8", "\u06F8", "\u06F8" },      //59 8
    {57, "\u06F9", "\u06F9", "\u06F9", "\u06F9", "\u06F9" },      //60 9
    {41, "\u0028", "\u0028", "\u0028", "\u0028", "\u0028" },      //61 (  
    {40, "\u0029", "\u0029", "\u0029", "\u0029", "\u0029" }       //62 )
};

#define N_DISTINCT_CHARACTERS           62

#endif


