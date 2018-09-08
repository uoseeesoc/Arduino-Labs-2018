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
#define UPDT_RT 5000        //The update rate of the neopixel shield in MILLISECONDS

//Neopixel Colour definitions, all values can be between 0 and 255
#define MAX_BRGHTNSS 20    //The maximum brightness of the LEDs

//VARIABLES - Contains valuees that will be changed whilst the code is running
//Generates a connection to the Neopixel Strip on the specified pin for the specified number of neopixels
Adafruit_NeoPixel neopxls = Adafruit_NeoPixel(NMBR_OF_NEOPXLS, PIN_NEOPXLS, NEO_GRB + NEO_KHZ800);

//Variables used to generate the England Flag Colours
unsigned int red[3] = {255, 0, 0};
unsigned int white[3] = {255, 255, 255};

unsigned int flag_colours[40] = {white, white, white, red, red, white, white, white,
                    white, white, white, red, red, white, white, white,
                    red, red, red, red, red, red, red, red,
                    white, white, white, red, red, white, white, white,
                    white, white, white, red, red, white, white, white};

//Variables used to track the execution of the program
unsigned long start_time = 0;

//FUNCTIONS - Contain sets of statements that we would like to use frequently in our code
//Sets all neopixles in the string to the specified RGB colour
void set_all_neopxl_colour(int red, int green, int blue){
  //Telling the neopixels what colour to change too
  for (int neopxl_indx = 0; neopxl_indx < NMBR_OF_NEOPXLS; neopxl_indx++){
    neopxls.setPixelColor(neopxl_indx, red, green, blue);
  }

  //Updating the neopixels colour
  neopxls.show();
}

//Sets the colour of a single neopixel in the string
void set_neopxl_colour(int red, int green, int blue, int neopxl_indx){
  neopxls.setPixelColor(neopxl_indx, red, green, blue);
}

//SETUP - Only run once, used for initial hardware and software setup
void setup(){
  //Beginning Serial Communictions
  Serial.begin(115200);
  
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
  
  //For all neopixels
  for (int neopxl_indx = 0; neopxl_indx < NMBR_OF_NEOPXLS; neopxl_indx++){
    //Getting the colour of the current neopixel to generate the England Flag
    int* neopxl_colour = flag_colours[neopxl_indx];

    //Setting the colour of the current neopixel
    set_neopxl_colour(neopxl_colour[0], neopxl_colour[1], neopxl_colour[2], neopxl_indx);
  }

  //Updating the Neopixels
  neopxls.show();

  //Waiting until the time delay has passed
  while (millis() - start_time <= UPDT_RT){}
}
