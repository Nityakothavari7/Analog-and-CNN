# Wrist Rehabilitation System for CTS patients
The aim of this project is to develop a cost-effective wearable device for Carpal Tunnel Syndrome(CTS) which is compression on the median nerve within the Carpal Tunnel in the wrist.It provides therapy after predicting the CTS using FeedForward Neural Network(FNN). It makes use of Servo Motors to provide a feedback and creates a personalised experience for the user.
## Dataset Acquisition
We took dataset from kaggle which measures EMG signals at various wrist gestures like hand at rest, wrist flexion, wrist extension, radial deviations and ulnar deviations. Here is the link for the dataset 
https://www.kaggle.com/code/sojanprajapati/emg-signals-for-hand-gesture-classification-r
## Hardware components
EMG Sensor - Detects the electrical activity of the wrist muscle to classify EMG signals as 'CTS Detected' or 'No CTS'
ESP32 Vroom - A mircocontroller which acts interface between sensors and the motor
MPU6050 - Measures the acceleration and rotation of the wrist
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
