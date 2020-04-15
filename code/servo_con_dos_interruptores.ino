#include <Servo.h>        //Implement Servo library
Servo mi_servo;           //Declare the Servo function

int grados= 0;            //Initialize in 0º
int suma = 8;             //Declare the button that increase the angle
int resta = 9;            //Declare the button that decrease the angle


void setup() {                         //Configure initial parameters
  
   mi_servo.attach(2,750,1800);        //Configure the servo, in this case 750ms = 0º and 1800ms = 180º 
   pinMode(suma, INPUT);               //Configure the input pins
   pinMode(resta, INPUT);
   mi_servo.write(grados);             //Move the servo until the number of degrees, in this case 0º
}


void loop() {
  
   if (digitalRead(suma) == LOW)           //Ask for 'suma' button and it is activated with a Low state, when it is at 0V (because it is normally connected at 5V)
   {
     grados++;                             //Increase degrees
     
     if (grados>180)                       //Protect the servo motor to not exceed 180º
     {
       grados=180;
     }
   } 
   if (digitalRead(resta) == LOW)          //Ask for 'resta' button and it is activated with a Low state
   {
      grados--;                            //Decrease degrees

     if (grados<=0)                        //Protect the servo motor to not decrease more than 0º
     {
       grados=0;
     }
   }
   mi_servo.write(grados);                //Write a new angle in degrees
   delay(10);                             //Delay to have a good lecture of the Servo and Arduino
}

  
