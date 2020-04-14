# UICduinohand
Project of the prosthetic hand:

_Objectives_: 
- Learn the basics of 3D printing and electronics in order to create a prosthetic hand controlled with the Cthulhu Shield sensor.
- Use motors and electronic devices in order to understand its functions.

_Materials_:
- **For 3D printing**:
  - PLA for the entire hand except the junctions that are of TPU.
  - Ultimaker 2+.
  - Sandpaper. (To polish the final pieces).
- **For the electronics of the hand**:
  - Arduino MKR 1000 WIFI.
  - Servo motors. 
  - Cthulhu Shield sensor.
  - Arduino cables.
  - Straw / 3D printed tube. (To guide the thread from the fingers to the servo).
  - Fishing line.
  
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

_Results_:

For this project, we just wanted to create a movement of close/open the hand, therefore with one servo we have enough to move all the fingers at the same time. However, as the fingers are in different positions we need to use a straw or a 3D printed tube (_depending on the circumstances of the quarantine, because the best option is a 3D printed tube because offers better resistance, but if we are not able to use the 3D printer of the lab then a straw is also useful_) to guide the fishing line of each finger to the servo motor.

We decided to use the same thread material that is used in fishing because is transparent (_hence give a better view of the prosthetic hand_) and offers better elasticity than others. Moreover, the length of the fishing line needed depends on the size of your prosthetic hand, in our case we will need -------cm.

On the other side, to distribute the motor servos, the Arduino MKR and the guide tubes inside the box of the prosthetic hand, we have plenty of options, for example: use a vertical servo and a drum to role the thread, use a vertical servo and a gripper... But due the design of the box we had limitations in which option to choose, hence the option that we choosed is to use a horitzontal servo (_because the height of the box is not high enough_) that goes from 0-80 degrees with a guide tube. See the image bellow:
![design of the position servo](https://github.com/roboticsuic/UICduinohand/blob/master/3D%20files/images/guidetubedesignneedstobechanged.png)--------we need to change the image for the good one.

Doing reference to the code and the scheme, the code is designed to be able to maintain a certain position of the hand until the MKR recieve a new input to change the position, in that way, we avoid the patient to exercise compression force in the Cthulhu constantly generating fatigue. To continue as we don't have in thinkercad nor in physic the Cthulhu sensor, we used two buttons to simulate the Cthulhu sensor function of closing and opening the prosthetic hand.

SolidWorks:-------

Unity:--------

_Conclusions_:
  
We believe that human's the simplest happiness come from physical activity.
