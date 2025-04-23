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
 ## Data filtering 
- Filter channels: Flexion, Extension, and Standard position's EMG measures .
- CTS_labels: If CTS_label = 0(No Cts), CTS_label = 1(Mild) CTS_Label=2(Moderate) CTS_Label=3(Severe).
 ## Class filtering:
- Removed classes from the dataset that are not necessary
 ## Handling missing values:
- Filling missing values using a moving range for smooth gaps in EMG signals.
 ## Windowing:
- With a size of 50 each window is split and for overlapping a 25-sized window is used.
 ## Threshold values assigning:
- Took 45 degrees as threshold for CTS from research papers.
 ## Label assigning:
- Assigning a label to each window by using the median of CTS_label values


## Arduino Setup and interfacing
- Configured the hardware, including the Arduino Uno and the EMG sensor(EMGSEN).
- Connected the EMG sensor: VCC to 5V, GND to GND, and Signal Output to A0 on the Arduino. 
- Installed necessary drivers, including the CP210x USB to UART driver, to enable communication between Arduino and the PC.
- Uploaded a basic script in Arduino IDE to read analog values from the EMG sensor and display them in the Serial Monitor. 
- Faced initial issues with constant values instead of dynamic muscle signals, which were resolved by verifying wiring, electrode positioning, and ensuring proper skin contact.
- Successfully started reading and displaying EMG values, marking the transition to data transmission and processing.
- Integrated the EMG sensor with Arduino and started recording and analyzing muscle activity signals to identify CTS.
- Connected electrodes to the wrist muscles to capture electrical signals and read them using the A0 analog input pin on the Arduino.
- Displayed live EMG readings on the Serial Monitor for verification.
  
## CLOUD INTERFACING
- Arduino lacks built-in WiFi, created a communication bridge using a laptop. - Wrote a Python script to read EMG values from Arduino through serial communication (COM port) and transfer them to a Flask-based cloud server.
- Hosted the cloud server on the same PC and programmed it to process incoming EMG signals. 
- Used a Recurrent Neural Network (RNN) model trained to classify whether CTS was present or not based on real-time EMG data.
- Trained the RNN model using filtered EMG data with TensorFlow and converted it to TensorFlow Lite (TFLite) for optimized processing on the cloud server.
- Flask API received EMG values from Arduino and used the trained RNN model for prediction.
- The model classified the result as either CTS detected (1) or No CTS (0) and returned the prediction to the Arduino.
- Once the prediction was received from the cloud, displayed the final result on an OLED screen connected to the Arduino.
- The OLED displayed either "CTS Detected" or "No CTS" based on the model’s classification. 

Used the following Python libraries:
- Flask – To set up the cloud server and handle API requests.
- requests – To send EMG data from Arduino to the cloud.
- serial – To read EMG data from Arduino through serial communication.
- TensorFlow and TensorFlow Lite – For training the RNN model and optimizing it for deployment. 
- NumPy and Pandas – For data processing and structuring EMG data.
- Matplotlib – To visualize training loss and accuracy for model evaluation.
- scikit-learn – For data preprocessing, including normalization and train-test splitting.

