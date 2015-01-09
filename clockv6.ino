#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include <ClockLib.h>

// define pins
#define PIN 13
#define MINBUTTON 12
#define HOURBUTTON 11
#define TOGGLE 4
#define DIMMER 5
#define PHOTORES A1
#define POT A0

Clock clock; // Holds current clock time

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

byte hourval, minuteval, secondval;                  // holds the time
byte pixelColorRed, pixelColorGreen, pixelColorBlue; // holds color values
int dimmer = 0, toggle = 0;                          // holds button press numbers
int sensorValue, mainLights, hourLights;             // holds brightness values for lights
int photoResistMin = 500, photoResistMax = 501;      // holds ranges for room brightness
int maxBright, maxBrightTick = 0, brightness;        // holds maximum brightness based on sensorValue

void setup() {
  pinMode(MINBUTTON,INPUT);
  pinMode(HOURBUTTON,INPUT);
  pinMode(TOGGLE,INPUT);
  pinMode(DIMMER,INPUT);
  
  Wire.begin();        	// Begin I2C
  Serial.begin(9600);
  
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  updateTime(); // initialize all time values
}

void loop() { 
  strip.setBrightness(brightness);
  if (toggle == 0) simpleClock();
  
  else if (toggle == 1) onlineClock();
  
  else if (toggle == 2) rainbowClock();
  
  else easyClock();
    
  brightnessRangeUpdate(); // updates brightness maximum and minimum
  updateLightBright();  // updates brightness based on POT and PHOTORESISTOR
  toggleCheck();  // checks to see if the toggle button has been pressed to change clocks
  dimmerCheck();  // checks if the dimmer button has been pressed
  minuteCheck();  // checks if minute and hour have been changed
  hourCheck();
}







