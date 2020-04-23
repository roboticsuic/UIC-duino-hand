# UICduinohand 
## PROJECT: **Prosthetic hand controlled by a tongue sensor**
This project is based on the manufacture of a prosthetic hand, a device designed to help those with loss of hand and forearm to retain the function and appearance of the missing section. Here we intend to report on how we created an electric prosthetic hand that has a set of fully articulated fingers. The wearer can manipulate the hand by moving a specific part of their body, in this case the tongue. It is a very innovative project because through a tongue sensor, which has built-in electrodes that show the signals of the tongue tactilely, we connect it to a 5V Arduino plate allowing to activate a movement of our prosthetic hand as it is the clamping (hand close and open).
The project is developed on the basis of a previous project that we found in thingiverse (https://www.thingiverse.com/thing:1275967), where we got the hand model that we decided to print in 3D.

_Objectives_: 
- Learn the basics of 3D printing and electronics in order to create a prosthetic hand controlled with the Cthulhu Shield sensor.
- Use motors and electronic devices in order to understand its functions.

_Materials_:
- **For 3D printing**:
  - PLA 
  - TPU (for the junctions)
  - Ultimaker 2+ (3D printer)
  - Sandpaper
- **For the electronics of the hand**:
  - Arduino MKR 1000 WIFI
  - Servo motor (nombre del tipo)
  - Cthulhu Shield sensor
  - Arduino cables
  - Straw / 3D printed tube
  - Fishing line
- **Softwares**:
  - Unity 3D (to create animations and represent how the prosthetic hand works)
  - SolidWorks (to create some pieces that we need)
  - Ultimaker Cura (to adjust setting parameters of the 3D printer)
  
  
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
- RC plane "9g" servo motor. 
- We took it from: https://grabcad.com/library/9g-servo-motor-1 (modelled and rendered in Solidworks)

![servo-motor](https://github.com/roboticsuic/UICduinohand/blob/master/3D%20files/images/servo%20motor.png)

Here we can see some important aspects to considerabout this servo motor:
![dimensionsservo] (https://github.com/roboticsuic/UICduinohand/blob/master/3D%20files/images/dimesionsservo.png)

**Cthulhu Shield sensor**: 

The Cthulhu Shield is an open-source Arduino Uno compatible sensory substitution/sensory augmentation device. It uses an 18 electrode grid to tactile display signals on the tongue. The electrodes on the array can be activated with patterns of electrical pulses to depolarize nerve membranes in the tongue to create different types of touch sensations. You can use these touch sensations to draw shapes or simple images on the tongue, feel different sound frequencies, or receive turn by turn directions with your tongue.
Additionally, the Cthulhu Shield can sense whether or not your tongue is in contact with different electrodes using capacitive sensing. You can use the Cthulhu Shield to send keystrokes to your computer, control the cursor, or even control a mobility device.

Good video explanation: https://www.youtube.com/watch?time_continue=197&v=wd38Go9tbds&feature=emb_title

_Results_:

For this project, we just wanted to create a movement of close/open the hand, therefore with one servo we have enough to move all the fingers at the same time. However, as the fingers are in different positions we need to use a straw or a 3D printed tube (_depending on the circumstances of the quarantine, because the best option is a 3D printed tube because offers better resistance, but if we are not able to use the 3D printer of the lab then a straw is also useful_) to guide the fishing line of each finger to the servo motor.

We decided to use the same thread material that is used in fishing because is transparent (_hence give a better view of the prosthetic hand_) and offers better elasticity than others. Moreover, the length of the fishing line needed depends on the size of your prosthetic hand, in our case we will need --- cm.

On the other side, to distribute the motor servos, the Arduino MKR and the guide tubes inside the box of the prosthetic hand, we have plenty of options, for example: use a vertical servo and a drum to role the thread, use a vertical servo and a gripper... But due the design of the box we had limitations in which option to choose, hence the option that we choosed is to use a horitzontal servo (_because the height of the box is not high enough_) that goes from 0-180 degrees with a guide tube. See the image bellow:

![hole hand ensambled](https://github.com/roboticsuic/UICduinohand/blob/master/3D%20files/images/holeprothetic.jpg)

![design of the position servo](https://github.com/roboticsuic/UICduinohand/blob/master/3D%20files/images/guidetubedesignneedstobechanged.png)--------we need to change the image for the good one.

Doing reference to the code and the scheme, the code is designed to be able to maintain a certain position of the hand until the MKR recieve a new input to change the position, in that way, we avoid the patient to exercise compression force in the Cthulhu constantly generating fatigue. To continue as we don't have in thinkercad nor in physic the Cthulhu sensor, we used two buttons to simulate the Cthulhu sensor function of closing and opening the prosthetic hand.

With this code our aim is to control a servo motor with 2 buttons that simulate the Cthulhu sensor function. In this case, one button is to move the hand from 0º to 180º (to open the hand) and the other one is to move the hand from 180º to 0º (to close the hand). In the case of the Cthulhu sensor, one electrode will be to open the hand and another to close it. 

Now, we are going to explain the **schematic image** which shows the connection of the Arduino with the electronic elements:

![servo with two pushbuttons](https://github.com/roboticsuic/UICduinohand/blob/master/code%20schematics/servo%20with%20two%20pushbuttons.png)


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
For a better final result of the 3D printed pieces we used sandpaper to polish them. Moreover, we had to modify the box where we put the electronics to optimize the space and put an arduino mkr, although the use of smaller arduinos to control servos would be a more suitable option.

**Unity**:--------

_Conclusions_:

We could conclude this project by saying that we have learned different variables to take into account when creating a prosthesis. We have been able to program with Arduino, seeing how we must create the circuit and the code, facing the circumstances that we had, simulating with buttons the function of the sensor to close and open the hand. And we have put the design into practice, whether it is at the level of computer aided design for 3D mechanical modeling, or for creating virtual reality visualizations.
On the other hand, talking about what we are trying to replace, in this case the hand, we saw that it has many movements, of which we have focused only on recreating one of them. As a future project, we think it would be great to be able to incorporate more and more movements, perhaps progressively, to give those who require the prosthesis a high degree of freedom.
Also we have been able to see that the language sensor we have used in the project can have many uses, including the development of sensory substitution. It is very interesting to contemplate the idea that sensory substitution tools and techniques take the sensory information normally received in one organ can be presented in another way to another sensory organ. So we would be talking about recovering the sensory information that has been lost, and learning to process it through another organ.

Most importantly, we believe that the **simplest human happiness comes from physical activity**, and we have been able to provide an option to reclaim it.


