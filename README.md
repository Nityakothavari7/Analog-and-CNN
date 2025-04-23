# Wrist Rehabilitation System for CTS patients
This project aims to develop a cost-effective wearable device for Carpal Tunnel Syndrome(CTS) which is compression on the median nerve within the Carpal Tunnel in the wrist. It provides therapy after predicting the CTS using a Recurrent Neural Network(RNN). It makes use of Servo Motors to provide feedback and creates a personalized experience for the user.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
## Dataset Acquisition
Syntehtic dataset was created by tracking real time EMG data(milliVolts converted to degrees at two positions 0 and 90)
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
## Hardware components
   ## 1. Arduino Uno:
   ![image](https://github.com/user-attachments/assets/59803a27-3323-4178-9c82-02f85ee22182)
        
         Microcontroller: ATmega328P
         Operating Voltage: 5V
         InputVoltage (recommended): 7-12V
          Digital I/O Pins: 14 (6 PWM)                                                                                                                                         
          AnalogInput Pins: 6
          FlashMemory: 32 KB(0.5 KB used by bootloader)
          SRAM:2KB
          EEPROM:1KB
          ClockSpeed: 16 MHz
          Communication: UART, I2C, SPI
         
   Use in our project:
      Platform and interface to integrate all the sensors and motors used in the project.
  -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------    
 ## 2. EMGsensor:
 ![image](https://github.com/user-attachments/assets/3c8a7b68-b335-49ab-b66e-0f510ed4e294)

       Microcontroller: ATmega328P
       Operating Voltage: 5V
       InputVoltage (recommended): 7-12V
       Digital I/O Pins: 14 (6 PWM)
       AnalogInput Pins: 6
       FlashMemory: 32 KB(0.5 KB used by bootloader)
       SRAM:2KB
       EEPROM:1KB
       ClockSpeed: 16 MHz
       Communication: UART, I2C, SPI
 Use in our project:
   1. Captures electrical signals from wrist muscles during movement.
   2. Variance in EMG signals is analyzed using a threshold-based approach (e.g., 75th
   percentile method) to detect CTS-related abnormalities.
   3. If abnormal EMG signals persist, the system can recommend therapy adjustments
   (e.g., increased rest periods, different wrist angles).
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ## 3.Servo motor (DS5160):
  ![image](https://github.com/user-attachments/assets/69e09c04-0001-4968-8d4b-97af736773a2)

    Operating Voltage: 4.8V– 7.4V
    Torque: 60 kg·cm (at 7.4V)
    Speed:0.16 sec/60° (at 7.4V)
    Control Signal: PWM (50Hz)
    AngleRange: 0° to 180° (or continuous rotation mode)
    Gears: Metal gears for durability)
    
 Use in our project:
   1. Controlled Wrist Positioning for Therapy
   2. Adaptive Feedback Mechanism
   3. Real-Time Movement Correction
   4. Personalized Therapy Adjustments
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ## 4.OLEDSSD1360
 ![image](https://github.com/user-attachments/assets/98e5cff6-ed2b-4bbd-846c-35d427ff8d05)

     Resolution: 128 × 64 pixels
     Display Type: Monochrome OLED
     Interface: I2C (4-pin) or SPI (7-pin)
     Operating Voltage: 3.3V– 5V
     PowerConsumption: Low
     Driver IC: SSD1306
     
 Use in our project:
   1. Organic Light-Emitting Diode display uses the powerful
   single-chip CMOS OLED driver controller, the SSD1306.
   2. It displays the EMG value along with the detection.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
## Software used
 Python is used for pre-processing and training the model with RNN.
 Arduino IDE is used for programming Arduino UNO
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Methodology 
 ## Data Collection
- We collected Surface Electromyography (sEMG) signals by placing the gel electrodes on the Extensor Carpi Radialis (ECR) muscle once at 0°(relaxed position) and the other at 90°(extended position). In total 100 readings were collected at each position, and a dataset of 1000 samples was linearly interpolated for all wrist angles between 0° and 90°.

## Long Short-Term Memory (LSTM) Model
After preprocessing CTS labels were one-hot encoded to enable multiclass classification.TensorFlow and Keras libraries was used to built the model, employing the LSTM layer to capture long-term dependencies in muscle signal patterns. We tuned hyperparameters including sequence length, batch size, number of LSTM units, learning rate, activation functions, epochs, and dropout rate to improve perfor mance and prediction accuracy for CTS detection.
  
## CLOUD INTERFACING
- Real-time EMG signals are read from Arduino through serial communication and then sent to a Flask-based cloud server. The Flask API receives a sequence of 10 EMG values and uses the converted TensorFlow Lite (TFLite) model to predict the severity of CTS.

## Prototype design and 3D printing
The exoskeleton was designed using Fusion 360. The design includes a semi-open wrist brace with place for the DS5160 servo motor, a flexible platform for Arduino and EMG sensor placement. Further, Servo shaft is connected to palm gear using ball bearing. Polyethylene Terephthalate Glycol(PETG) was used for 3D printing the prototype due to its balance of strength, flexibility and duration.

## Hardware Integration

1: EMG Sensor: Captures muscle electrical activity.
2: Arduino UNO Microcontroller: Used to receive data,
control the servo motor, and display output.
3: OLED Display (SSD1306): Used to visually display the
CTS prediction result.
4: Servo Motor DS516: Provides the actuation for wrist
movement therapy.
5: Power Supply: Powers the Arduino and components.
6: Jumper Wires: For connections between components.
Circuit Connections:
1) EMG sensor:
SIG → A0
GND → GND
Vs+ → 9V(1st battery)
Vs- → GND
GND → Midpoint of conection between
9V and GND of the two batteries
2) OLED Display:
VCC → 5V
GND → GND
SDA → A4 (Arduino UNO)
SCL → A5 (Arduino UNO)
3) Servo Motor:
Signal → Digital pin
VCC → External power source
GND → Common GND with Arduino

## Actuation (Therapy)

Once the EMG values are read it is sent to the cloud server where the values are classified using the RNN model which will predict wrist movement angle. According to the given threshold values if the individual is detected with CTS the therapy is given in such a way that along with the wrist movement angle +5° angle is added for the therapy. Then this angle is sent to Arduino through the serial communication. The Arduino receives the angle and then it will trigger servo motor to move the wrist to the calculated therapeutic angle.


