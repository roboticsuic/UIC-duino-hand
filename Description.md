# UICduinohand
Project of the prosthetic hand:

_Objectives_: 
- Learn the basics of 3D printing and electronics in order to create a prosthetic hand controlled with the Cthulhu Shield sensor.
- Use motors and electronic devices in order to understand its functions.

_Materials_:
- **For 3D printing**:
  - PLA for the entire hand except the junctions that are of TPU.
  - Ultimaker 2+.
  - Sandpaper. 
- **For the electronics of the hand**:
  - Arduino MKR 1000 WIFI.
  - Servo motors. 
  - Cthulhu Shield sensor.
  - Arduino cables.
  - Straw / 3D printed tube. 
  - Fishing line.
- **For Unity 3D**:
  - Unity software.
  
_Definitions_:

**MKR 1000 WIFI**:
- Price: €26.50 [https://store.arduino.cc/arduino-mkr1000-wifi].
- Size: Length 61.5mm Width 25mm.
- Weight: 32gr.
- Microcontroller: SAMD21 Cortex-MO + 32bit low power ARM MCU.
- Board Power Supply (USB/VIN): 5V.
- Supported Battery: Li-Po single cell, 3.7V, 700mAh minimum.
- Circuit Operating Voltage: 3.3V
- Digital I/O Pins: 8.
- PWM Pins: 12 (0,1,2,3,4,5,6,7,8,10,A3 -or 18 -, A4 -or 19).
- UART: 1.
- SPI: 1.
- 12C: 1.
- Analog Input Pins: 7 (ADC 8/10/12 bit).
- Analog Output Pins: 1(DAC 10 bit).
- External Interrupts: 8(0,1,4,5,6,7,8,A1 -or 16-, A2 - or 17).
- DC current per I/O Pin: 7mA.
- Flash Memory: 256KB.
- SRAM: 32KB.
- EEPROM: no.
- Clock Speed: 32.768kHz (RTC), 48MHz.
- LED_BUILTIN: 6.
- Full-speed USB Device and embedded Host.

**Servo Motor**:
- 9g. https://grabcad.com/library/9g-servo-motor-1
![servo-motor](https://github.com/roboticsuic/UICduinohand/blob/master/3D%20files/images/servo%20motor.png)
![dimensionsservo](https://github.com/roboticsuic/UICduinohand/blob/master/3D%20files/images/dimesionsservo.png)

**Cthulhu Shield sensor**: 

The Cthulhu Shield is an open-source Arduino Uno compatible sensory substitution/sensory augmentation device. It uses an 18 electrode grid to tactile display signals on the tongue. The electrodes on the array can be activated with patterns of electrical pulses to depolarize nerve membranes in the tongue to create different types of touch sensations. You can use these touch sensations to draw shapes or simple images on the tongue, feel different sound frequencies, or receive turn by turn directions with your tongue.
Additionally, the Cthulhu Shield can sense whether or not your tongue is in contact with different electrodes using capacitive sensing. You can use the Cthulhu Shield to send keystrokes to your computer, control the cursor, or even control a mobility device.

Good video explanation: https://www.youtube.com/watch?time_continue=197&v=wd38Go9tbds&feature=emb_title

**Results**:

For this project, we just wanted to create a movement of close/open the hand, therefore with one servo we have enough to move all the fingers at the same time. However, as the fingers are in different positions we need to use a straw or a 3D printed tube (_depending on the circumstances of the quarantine, because the best option is a 3D printed tube because offers better resistance, but if we are not able to use the 3D printer of the lab then a straw is also useful_) to guide the fishing line of each finger to the servo motor.

We decided to use the same thread material that is used in fishing because is transparent (_hence give a better view of the prosthetic hand_) and offers better elasticity than others. Moreover, the length of the fishing line needed depends on the size of your prosthetic hand, in our case we will need -------cm.

On the other side, to distribute the motor servos, the Arduino MKR and the guide tubes inside the box of the prosthetic hand, we have plenty of options, for example: use a vertical servo and a drum to role the thread, use a vertical servo and a gripper... But due the design of the box we had limitations in which option to choose, hence the option that we choosed is to use a horitzontal servo (_because the height of the box is not high enough_) that goes from 0-180 degrees with a guide tube. See the image bellow:
![design of the position servo](https://github.com/roboticsuic/UICduinohand/blob/master/3D%20files/images/guidetubedesignneedstobechanged.png)--------we need to change the image for the good one.

Doing reference to the code and the scheme, the code is designed to be able to maintain a certain position of the hand until the MKR recieve a new input to change the position, in that way, we avoid the patient to exercise compression force in the Cthulhu constantly generating fatigue. To continue as we don't have in thinkercad nor in physic the Cthulhu sensor, we used two buttons to simulate the Cthulhu sensor function of closing and opening the prosthetic hand.

With this code our aim is to control a servo motor with 2 buttons that simulate the Cthulhu sensor function. In this case, one button is to move the hand from 0º to 180º (to open the hand) and the other one is to move the hand from 180º to 0º (to close the hand). In the case of the Cthulhu sensor, one electrode will be to open the hand and another to close it. 

Now, we are going to explain the **schematic image** which shows the connection of the Arduino with the electronic elements: 

  - As we can see, the 5V is connected to the positive pole of the servo as a supplying power. 
  - The ground (GND) is connected to the ground black cable as a reference to all other electronic parts, where the electrical level is at 0 V. 
   - The other cable is the signal to move the servo motor to the required angle, that signal corresponds to a PWM (Pulse Width Modulation, a technique for getting analog results with digital means). This cable is connected to the pin 2. 

Then, we have to connect the 2 buttons and 2 resistances for increasing or decreasing the angle. Negative poles are connected to GND and positive ones are connected to pins 8 and 9 with a resistance respectively. 

Regarding the **code**: 

At first, we have to implement the **Servo.h** library and we have declared the function Servo called as **mi_servo**. 
Then, we declare **3 variables integer**. The first one indicates the initial position (which in this case is 0º) and the second and third ones refers to the buttons that increase or decrease the angle.

After this, **void setup** is used to configure the initial parameters:
    - mi_servo.attach (2,750,1800): We use the attach function to attach the servo variable to a pin, where 2 refers to the pin 2 connected to the servo. In PWM, 750 ms represents 0º and 1800 ms represents 180º. It is a conversion from servo pulses to degrees.
   - Then, we configure the input pins with pinMode
   - Initialize your servo motor with the function ’’.write’’, in this case it will move 90º


In the **void loop**, we have 2 conditions ‘’if’’.
- ‘digitalRead’ function: It asks for the pin 8 and it is activated with a LOW state. And with ‘grados++’ you start increasing the degrees. The following condition if is to protect the servo motor, it is a condition for the motor to not exceed the 180º.

- The second big condition is the same but it corresponds to the pin9, and ‘grados - -' reduces the degrees. And the following condition guarantee to get to 0º and to not exceed it. 

- mi_servo.write (grados): It writes a new angle in degrees
- delay(10); It is used to write between degrees and present a good lecture in Arduino and the servo.






**SolidWorks**:-------
For a better final result of the 3D printed pieces we used sandpaper to polish them.

**Unity**:--------

**Conclusions**:
  
**We believe that the simplest human's happiness come from physical activity.**

The project was based on a previous project done in thingiverse.(https://www.thingiverse.com/thing:1275967)
