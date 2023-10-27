/********************************************************************************************

                       EEPROM-Cleaner v1.2.0

                       Copyright (c) 2017 Helmut Stult (schinfo)

 ********************************************************************************************/

#include <EEPROM.h>
#include <ESP8266WiFi.h>

// sizeBytes being the number of bytes you want to use.
// It's defined with "#define sizeBytes"
// Size can be anywhere between 4 and 4096 bytes (Default for ESP8266_deauther = 4096)
#define sizeBytes 4096

// change it for lower or higher endByte (Default for ESP8266_deauther = 4096)
// normaly it's the same as sizeBytes
#define endByte 4096

// change it for lower or higher startByte (Default = 0)
#define startByte 0


void setup()
{
  Serial.begin(115200);
  EEPROM.begin(sizeBytes);

  delay(100);
  byte line = 0;

  Serial.print("Printing EEPROM from "); Serial.print(startByte); Serial.print(" to "); Serial.println(endByte - 1);
  Serial.println("**********************************************************************************************************");
  Serial.print("("); Serial.print(nf(0, 4)); Serial.print(")|"); 

  for (int i = startByte; i < endByte; ++i)
  {
   
    Serial.print(nf(EEPROM.read(i), 3));  Serial.print(" | ");

    if(i % 16 == 15){

      line++;

      Serial.println();
      Serial.print("("); Serial.print(nf(i, 4)); Serial.print(")|"); 
    }

      
  }
  Serial.println("**********************************************************************************************************");
}

String nf(int num, int width){

  int digits = 0;

  if(num < 10)
    digits = 1;
  
  else if(num < 100)
    digits = 2;

  else if(num < 1000)
    digits = 3;

  else if(num < 10000)
    digits = 4;

  String s = String(num);

  if(digits != width)
    for(int i = digits; i < width; i++)
      s.concat(" ");

  return s;
}


void loop()
{
}