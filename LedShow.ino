// This program is a slight variation of the fade program on the Arduino website.
// See https://www.arduino.cc/en/Tutorial/Fade for original.
// Feel free to use this if you want.

#include <stdio.h>

#define STARTINGPIN 2

unsigned char leds = 0; // 1 bit per led indicating whether it is on or off
unsigned char* ledsPtr = &leds;

unsigned int brightness[8];
unsigned int* brightnessPtr = &brightness[0];

void setup() 
{
  *ledsPtr = 0;

  // sets initial brightness for each led
  for(int i = 0; i < 8; i++)
  {
    brightnessPtr[i] = 255;
  }

}

void loop() 
{
  writeToLeds(ledsPtr, brightnessPtr);

  (*ledsPtr)++;
  if(*ledsPtr >= 256)
    *ledsPtr = 0;

  delay(100);
}

// if the bit corresponding to a led is set to 1, write its brightness, otherwise, just turn it off
void writeToLeds(unsigned char* lPtr, unsigned int* bPtr)
{
  unsigned char mask = 1;
  
  for(int i = 0; i < 8; i++)
  {
    if((*lPtr & mask) == mask)
    {
      analogWrite(STARTINGPIN + i, bPtr[i]);
    }
    else
    {
      analogWrite(STARTINGPIN + i, 0);
    }

    mask <<= 1;
  }  
}

