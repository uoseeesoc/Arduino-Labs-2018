/*
 * This code is part of the University of Sheffield EEE Society Arduino Labs, Session Three. It makes the Adafruit Neopixel Shield
 * display random colours across all 40 LEDs. For more information about the society please visit our wesbite: www.eeesoc.com
 * 
 * DATE: 24/07/2018
 * AUTHOR: Sam Maxwell
 */
 
//LIBRARIES - Imports libraries of functions that we can use in the code
#include <Adafruit_NeoPixel.h>

//DEFINITIONS - Contains values that will not be changed whilst the code is running
//Neopixel setup definitions
#define NMBR_OF_NEOPXLS 40  //The number of neopixels we are interfacing with
#define PIN_NEOPXLS 6       //The pin the neopixel data line is connected too
#define UPDT_RT 1000        //The update rate of the neopixel shield in MILLISECONDS

//Neopixel Colour definitions, all values can be between 0 and 255
#define RED_MAX_VAL 255     //The maximum value the red channel can take
#define RED_MIN_VAL 0       //The minimum value the red channel can take
#define GRN_MAX_VAL 255     //The maximum value the green channel can take
#define GRN_MIN_VAL 0       //The minimum value the green channel can take
#define BLU_MAX_VAL 255     //The maximum value the blue channel can take
#define BLU_MIN_VAL 0       //The minimum value the blue channel can take
#define MAX_BRGHTNSS 255    //The maximum brightness of the LEDs

//VARIABLES - Contains valuees that will be changed whilst the code is running
//Generates a connection to the Neopixel Strip on the specified pin for the specified number of neopixels
Adafruit_NeoPixel neopxls = Adafruit_NeoPixel(NMBR_OF_NEOPXLS, PIN_NEOPXLS, NEO_GRB + NEO_KHZ800);

//Variables that store the brightness values of each of the colours: RED, GREEN, BLUE
int red = 0;
int green = 0;
int blue = 0;
unsigned long start_time = 0;

//FUNCTIONS - Contain sets of statements that we would like to use frequently in our code
//Sets all neopixles in the string to the specified RGB colour
void set_neopxl_colour(int red, int green, int blue){
  //Telling the neopixels what colour to change too
  for (int neopxl_indx = 0; neopxl_indx < NMBR_OF_NEOPXLS; neopxl_indx++){
    neopxls.setPixelColor(neopxl_indx, red, green, blue);
  }

  //Updating the neopixels colour
  neopxls.show();
}

//SETUP - Only run once, used for initial hardware and software setup
void setup(){
  //Initializing the Neopixel Strip
  neopxls.begin();  //Sets up the neopixel control pin
  neopxls.show();    //Sends a packet to the neopixels telling them to show no colour

  //Setting the maximum brightness of the Neopixel strip
  neopxls.setBrightness(MAX_BRGHTNSS);
}

//LOOP - Run continously, used for the main functionality of your code
void loop(){
  //Getting the current cycle start time
  start_time = millis();    //Gets the number of milliseconds since the program started running, useful for time delays!
  
  //Generating random values for each of the colours
  red = random(RED_MIN_VAL, RED_MAX_VAL + 1);     //Generates a random value between the minimum and maximum values
  green = random(GRN_MIN_VAL, GRN_MAX_VAL + 1);   //The maximum value is exclusive, so we add one!
  blue = random(BLU_MIN_VAL, BLU_MAX_VAL + 1);

  //Setting the colour of all of the Neopixels in the String
  set_neopxl_colour(red, green, blue);

  //Waiting until the time delay has passed
  while (millis() - start_time <= UPDT_RT){}
}
