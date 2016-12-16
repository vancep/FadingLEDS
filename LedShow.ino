// This program is a slight variation of the fade program on the Arduino website.
// See https://www.arduino.cc/en/Tutorial/Fade for original.
// Feel free to use this if you want.

#include <stdio.h>

#define NUMLEDS 8
#define STARTINGPIN 2

unsigned short leds[NUMLEDS];
unsigned short *ledPtr;

unsigned short brightness[NUMLEDS];
unsigned short *brightnessPtr;

unsigned short fadeAmount[NUMLEDS];
unsigned short *fadePtr;
  
void setup() 
{
  ledPtr = leds;
  brightnessPtr = brightness;
  fadePtr = fadeAmount;
  
  // assign each led a pin, set default brightness, set pin to output
  // Note: This loop is assuming that the pins are in consecutive locations
  for(unsigned short i = 0; i < NUMLEDS; i++)
  {
    // assign led
    *(ledPtr + i) = STARTINGPIN + i;

    // set default brightness for each pin
    *(brightnessPtr + i) = (255 / NUMLEDS) * i;

    // set pin to output
    pinMode(*(ledPtr + i), OUTPUT);

    // set fadeAmount
    *(fadePtr + i) = 5;
  }
}

void loop() 
{
  setBrightnessOfPins(ledPtr, brightnessPtr);

  updateBrightness(brightnessPtr);
}

void setBrightnessOfPins(unsigned short* lPtr, unsigned short* bPtr)
{
  for(unsigned short i = 0; i < NUMLEDS; i++)
  {
    analogWrite(*(lPtr + i), *(bPtr + i));
  }
}

void updateBrightness(unsigned short* bPtr)
{
  for(unsigned short i = 0; i < NUMLEDS; i++)
  {
    *(bPtr + i) = *(bPtr + i) + fadeAmount;

    if (*(bPtr + i) <= 0 || *(bPtr + i) >= 255) 
    {
      *(fadeAmount + i) = -1 * *(fadeAmount + i);
    }
  }
}

