## 📖 About
C/C++ UTF-8-only-supported-Platforms Library for Reconstructing Persian or Arabic sentences.

In languages like Persian/Arabic, the letter is modified depending on where it should go in a word. Usually, when you print to the display ordinary Persian/Arabic text, each character is printed individually and is not joined together, whereas a computer would join it automatically on the screen but not modifying the actual data of each character.

## 📚 Description
Persian/Arabic script is very special with two essential features:
- It is written from right to left.
- The characters change shape according to their surrounding characters.

So when you try to print text written in Persian/Arabic script on LCD/OLED display that doesn’t support Persian/Arabic you’re pretty likely to end up with something that looks like this:

<p align="center">
  <img src="http://mpcabd.xyz/wp-content/uploads/2012/05/arabic-1.png">
  <img src="https://github.com/HamidSaffari/UTF8_Persian_Arabic_Reshaper/blob/master/Pictures/STM32F103%2BILI9341.jpg">
</p>

Since Arduino and many low-level platforms do not support UTF-16 16-bit Unicode (wchart_t) inputs and functions so makes it hard to manipulate with chars inside words.

## 📷 Screenshot
<p align="center">
  <img width="516" height="600" src="https://github.com/idreamsi/u8g2-persian-reshaper/blob/master/screenshot.jpg?raw=true">
</p>

## ⚙️ Download & Usage
Download/Clone repository, then Put it in your Arduino Libraries folder.

## 📫 Contact
  Copyright (C) 2019 Ramin Sangesari (mailto:r.sangsari@gmail.com)
  https://github.com/idreamsi/u8g2-persian-reshaper
  
  Updated @ Apr 2020 by Hamid Saffari hamidsaffari@yahoo.com
  https://github.com/HamidSaffari/UTF8_Persian_Arabic_Reshaper
