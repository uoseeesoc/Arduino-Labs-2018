/*
 * This code is part of the University of Sheffield EEE Society Arduino Labs, Session Three. It makes the Adafruit Neopixel Shield
 * display random colours across all 40 LEDs. For more information about the society please visit our wesbite: www.eeesoc.com
 * 
 * DATE: 27/10/2018
 * AUTHOR: Sam Maxwell
 */
 //LIBRARIES - Imports libraries of functions that we can use in the code
#include <Adafruit_NeoPixel.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_GFX.h>

//DEFINITIONS - Contains values that will not be changed whilst the code is running
//Neopixel setup definitions
#define NMBR_OF_NEOPXLS 40  //The number of neopixels we are interfacing with
#define MTRX_WDTH 8         //The width of the Neopixel matrix in LEDs
#define MTRX_HGHT 5        //The length of the Neopixel matrix in LEDs
#define PIN_NEOPXLS 6       //The pin the neopixel data line is connected too

//Neopixel Colour definitions, all values can be between 0 and 255
#define MAX_BRGHTNSS 20    //The maximum brightness of the LEDs

//VARIABLES - Contains values that will be changed whilst the code is running
//Generating an Adafruit Neomatrix, allows for more complex patterns (Text, Shapes) to be generated
Adafruit_NeoMatrix neopxlMtrx = Adafruit_NeoMatrix(MTRX_WDTH, MTRX_HGHT, PIN_NEOPXLS, 
                              NEO_MATRIX_TOP + NEO_MATRIX_RIGHT + 
                              NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE, 
                              NEO_GRB + NEO_KHZ800);

//MATRIX COLOURS
int YELLOW = neopxlMtrx.Color(255, 255, 0);
int RED = neopxlMtrx.Color(255, 0, 0);
int BLUE = neopxlMtrx.Color(0, 255, 0);
int GREEN = neopxlMtrx.Color(0, 0, 255);

//Variables to track the position of the cursor on the Matrix
int row = 0, column = 0;

//SETUP - Only run once, used for initial hardware and software setup
void setup(){
  //Beginning Serial Commmunications for debugging
  Serial.begin(115200);

  //Initializing the Neopixel display
  neopxlMtrx.begin();
  neopxlMtrx.fillScreen(0);         //Setting the screen to black
  neopxlMtrx.setCursor(0, 0);       //Setting the cursor to the top left of the matrix
  neopxlMtrx.setBrightness(25);     //Setting the display brightness
  neopxlMtrx.setTextWrap(false);    //Stopping the matrix from wrapping text]
  neopxlMtrx.setTextColor(YELLOW);  //Setting the text colour to Yellow
}

//LOOP - Run continously, used for the main functionality of your code
void loop(){
  //Clearing the current display on the screen
  neopxlMtrx.fillScreen(0);
  neopxlMtrx.show();
  delay(300);

  //Drawing the rectangles
  neopxlMtrx.drawRect(0, 0, 8, 5, RED);
  neopxlMtrx.show();
  delay(300);
  neopxlMtrx.drawRect(1, 1, 6, 3, BLUE);
  neopxlMtrx.show();
  delay(300);
  neopxlMtrx.drawRect(2, 2, 4, 1, GREEN);
  neopxlMtrx.show();
  delay(300);
}
