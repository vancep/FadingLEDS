// This program is a slight variation of the fade program on the Arduino website.
// See https://www.arduino.cc/en/Tutorial/Fade for original.
// Feel free to use this if you want.

#include <stdio.h>

#define NUMLEDS 8
#define STARTINGPIN 2

int* ledPtr;
int* brightnessPtr;
int* fadePtr;

void setupLedPtr(int* lPtr);
void setupBrightnessPtr(int* bPtr);
void setupFadePtr(int* fPtr);

void writeBrightnessToPins(int* lPtr, int* bPtr);
void updateBrigntness(int* bPtr, int* fPtr);

void setup() 
{
  ledPtr = (int*) malloc(sizeof(int) * NUMLEDS);
  brightnessPtr = (int*) malloc(sizeof(int) * NUMLEDS);
  fadePtr = (int*) malloc(sizeof(int) * NUMLEDS);

  setupLedPtr(ledPtr);
  setupBrightnessPtr(brightnessPtr);
  setupFadePtr(fadePtr);
}

void loop() 
{
  writeBrightnessToPins(ledPtr, brightnessPtr);

  updateBrigntness(brightnessPtr, fadePtr);
}

void setupLedPtr(int* lPtr)
{
  for(int i = 0; i < NUMLEDS; i++)
  {
    *(lPtr + i) = STARTINGPIN + i;
  }
}

void setupBrightnessPtr(int* bPtr)
{
  for(int i = 0; i < NUMLEDS; i++)
  {
    *(bPtr + i) = (int)((255 / NUMLEDS) * i);
  }
}

void setupFadePtr(int* fPtr)
{
  for(int i = 0; i < NUMLEDS; i++)
  {
    *(fPtr + i) = 5;
  }
}

void writeBrightnessToPins(int* lPtr, int* bPtr)
{
  for(int i = 0; i < NUMLEDS; i++)
  {
    analogWrite(*(lPtr + i), *(bPtr + i));
  }
}

void updateBrigntness(int* bPtr, int* fPtr)
{
  for(int i = 0; i < NUMLEDS; i++)
  {
    *(bPtr + i) = *(bPtr + i) + *(fPtr + i);

    if (*(bPtr + i) <= 10 || *(bPtr + i) >= 255) 
    {
      *(fPtr + i) = *(fPtr + i) * -1;
    }
  }

  // wait for 30 milliseconds to see the dimming effect
  delay(100);
}

