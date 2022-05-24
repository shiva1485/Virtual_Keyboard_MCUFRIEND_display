#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
#include <TouchScreen.h>
#include"variable.h"

void setup()
{
  Serial.begin(9600);

  tft.begin(0x9486);
  tft.setRotation(0);
  tft.fillScreen(color[0]);
  delay(500);

  genkeys(8, 358);//generating the  keys

  delay(1000);
}

void loop()
{
  scankeys();

  //only touch keys are sensed
  if (con == true)
  {
    getxy(yindex, xindex);
    Serial.print("key:");
    Serial.println(keys[yindex][xindex]);

    if ('<' == keys[yindex][xindex])//backspace
    {
      int length = text.length() - 1;
      text.remove(length, 1);
      
      tft.fillRect(0, 0, 320, 340, color[0]);
      textprint(0, 0, 2, 3);
      tft.print(text);
      con = false;
    }
    else if ('*' == keys[yindex][xindex])//clear
    {
      text = "";
      tft.fillRect(0, 0, 320, 340, color[0]);
      textprint(0, 0, 2, 3);
      tft.print(text);
      con = false;
    }
    else//normal letters
    {
      text = text + keys[yindex][xindex];
      textprint(0, 0, 2, 3);
      tft.print(text);
    }
    con = false;
  }
}
