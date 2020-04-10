#include <Servo.h>
Servo mi_servo;


int grados= 90;

int suma = 8;

int resta = 9;



void setup() {
  
   mi_servo.attach(2,750,1800);
       pinMode(suma, INPUT);
       pinMode(resta, INPUT);
       mi_servo.write(grados); 
}


void loop() {
  
   if (digitalRead(suma) == LOW)
   {
     grados++;
     
     if (grados>180)
     {
       grados=180;
     }
    } 
    if (digitalRead(resta) == LOW)
    {
      grados--;

      if (grados<=0)
     {
       grados=0;
     }
    }
    mi_servo.write(grados);
    delay(10);
}

  
