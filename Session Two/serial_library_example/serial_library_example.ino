/*
 * This code is part of the University of Sheffield EEE Society Arduino Labs.It shows an example of the usage of the Serial
 * Library to Debug some code! For more information about the society please visit our website: www.eeesoc.com
 * 
 * DATE: 18/07/2018
 * AUTHOR: Sam Maxwell
 */

//VARIABLES - Contains valuees that will be changed whilst the code is running
int sm_rndm_vr = 0;

//SETUP - Only run once, used for initial hardware and software setup
void setup() {
  //Beginning a Serial Connection, by default this uses the Arduino USB Programming Port
  //The 9600 denotes the Baud Rate of the Connection in Bits per Second
  Serial.begin(9600);

  //Sending a message to let the user know the program is running
  Serial.println("Hello World from Arduino!");
}

//LOOP - Run continously, used for the main functionality of your code
void loop() {
  //Printing the current value of our variable
  //The print function allows you to send a string or variable without a newline character at the end
  Serial.print("Value of the Random Variable: ");

  //The println function allows you to send a string or variable with a newline character at the end
  Serial.println(sm_rndm_vr);

  //Incrementing the value of our variable
  sm_rndm_vr += 1;
}
