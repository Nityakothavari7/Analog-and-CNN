# Wrist Rehabilitation System for CTS patients
The aim of this project is to develop a cost-effective wearable device for Carpal Tunnel Syndrome(CTS) which is compression on the median nerve within the Carpal Tunnel in the wrist.It provides therapy after predicting the CTS using Reccurent Neural Network(RNN). It makes use of Servo Motors to provide a feedback and creates a personalised experience for the user.
## Dataset Acquisition
We took dataset from kaggle which measures EMG signals at various wrist gestures like hand at rest, wrist flexion, wrist extension, radial deviations and ulnar deviations. Here are two links one for the dataset the others explaining the features and labels
https://www.kaggle.com/datasets/sojanprajapati/emg-signal-for-gesture-recognition
https://www.kaggle.com/code/sojanprajapati/emg-signals-for-hand-gesture-classification-r

## Hardware components
  ## 1. Arduino Uno:
      Microcontroller: ATmega328P
      Operating Voltage: 5V
     InputVoltage (recommended): 7-12V
      Digital I/O Pins: 14 (6 PWM)
      AnalogInput Pins: 6
      FlashMemory: 32 KB(0.5 KB used by bootloader)
      SRAM:2KB
      EEPROM:1KB
      ClockSpeed: 16 MHz
      Communication: UART, I2C, SPI
     Use in our project:
     Platform and interface to integrate all the sensors and motors being used in the project.
  ## 2. EMGsensor:
      Microcontroller: ATmega328P
      Operating Voltage: 5V
      InputVoltage (recommended): 7-12V
      Digital I/O Pins: 14 (6 PWM)
      AnalogInput Pins: 6
     FlashMemory: 32 KB(0.5 KB used by bootloader)
      SRAM:2KB
      EEPROM:1KB
      ClockSpeed: 16 MHz
      Communication: UART, I2C, SPI
     Use in our project:
     1. Captures electrical signals from wrist muscles during movement.
     2. Variance in EMG signals is analyzed using a threshold-based approach (e.g., 75th
     percentile method) to detect CTS-related abnormalities.
     3. If abnormal EMG signals persist, the system can recommend therapy adjustments
     (e.g., increased rest periods, different wrist angles).
  ## 3.Servo motor (DS5160):
      Operating Voltage: 4.8V– 7.4V
      Torque: 60 kg·cm (at 7.4V)
      Speed:0.16 sec/60° (at 7.4V)
      Control Signal: PWM (50Hz)
      AngleRange: 0° to 180° (or continuous rotation mode)
      Gears: Metal gears for durability)
     Use in our project:
     1. Controlled Wrist Positioning for Therapy
     2. Adaptive Feedback Mechanism
     3. Real-Time Movement Correction
     4. Personalized Therapy Adjustments
  ## 4.OLEDSSD1360
      Resolution: 128 × 64 pixels
      Display Type: Monochrome OLED
      Interface: I2C (4-pin) or SPI (7-pin)
      Operating Voltage: 3.3V– 5V
      PowerConsumption: Low
      Driver IC: SSD1306
     Use in our project:
     1. Organic Light-Emitting Diode display uses the powerful
     single-chip CMOS OLED driver controller, the SSD1306.
     2. It displays the EMG value along with the detection.
Servo Motor (MG995) - It produces torque and velocity based on the supplied current and voltage. It receives PWM input signal from ESP32 and moves accordingly.
## Software used
MATLAB - for pre-processing and training the neural network model (FNN)
Arduino IDE - for programming ESP32
## Review 2
As per the suggestions FNN is replaced with RNN.
Pre-Processing:
-> Data filtering 
    Filter channels: Flexion, Extension and Standard postion's EMG measures which are from channels 1, 4, 7 from the data set.
    CTS_labels: If CTS detected (from class 4,7) CTS_label = 1, no CTS detected then CTSA_LABEL = 0.
-> Class filtering:
    Removed classes from dataset which are not neccesary like time,
-> Handling missing values:
    Filling missing valuse using moving range fro smooth gaps in EMG signals.
-> Windowing:
    With a size of 50 each window is splitted and fro overlapping a 25 sized window is used.
-> Threshold values assigning:
    calcualted the varaince of the 3 EMG classes for each window.
-> Label assigning:
    Assigning label to each window by using medioan of CTS_label values 
## Hardware Components
in hardware componenets ESP32 is replaced with Arduino UNO cause the ESP32 which is used was not able to connect to WiFi. Label Assigning 
Using EMG sensor the muscle activity is measured and it is stored in Cloud 
## Software used
Python - fro pre-processing and training the model with RNN.
