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
