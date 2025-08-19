# EVO-DEVELOPERS_HTH_2k25

## Git Push(12:30 PM) ReadME File (Created)

# Problem Statement Title with ID:

 **Problem Statement:** 
Gesture-to-Speech Translator

ID : HTH_22


# Description of Project: 
A glove-based system converting hand gestures to speech/text, helping speech-impaired individuals communicate.


# Reduired Components :

1. NodeMCU ESP8266 :- As the Main Controller (Brain of the System)
2. MPU 6050 :- (For Detecting the Gestures with the particular angles)
3. 16x2 LCD Display (For Text Messages)
4. APR Tester (For Audio Messages of the Gestures)
5. Speaker ( For Listening Audio)

# Solution Approach:

1. **Gesture Detection**  
   -> The MPU6050 sensor detects hand movements and orientation (pitch, roll, yaw) by the angles.
   -> Each specific gesture corresponds to predefined angle thresholds.

2. **Data Processing**  
   -> The NodeMCU ESP8266 processes sensor values and identifies which gesture has been performed.  
   -> A mapping is created between gestures and corresponding words/phrases.

3. **Output Generation**  
   -> The identified gesture is displayed as text on the 16x2 LCD.  
   -> Simultaneously, the APR audio module generates pre-recorded voice outputs.  
   -> A speaker is used for audio playback so others can hear the translated speech.

4. **Communication Support**  
   -> This enables speech-impaired individuals to communicate effectively by simply performing hand gestures. 

**Git Push 1 Completed**
README.md file Created and pushed. (12:30 PM)

# Git Push 2
GLOVE.ino File (The Main Program for the system) Developed.
**Libraries used**
LiquidCrystal_I2C.h :- For LCD Dispay
MPU6050_tockn.h :- For MPU6050 Sensor
Wire.h :- For Communication between Sensors and Controller

# Working of the System
1. **Gesture Detection**  
   -> The MPU6050 sensor detects hand movements and orientation (pitch, roll, yaw) by the angles.
   -> Each specific gesture corresponds to predefined angle thresholds.

2. **Data Processing**  
   -> The NodeMCU ESP8266 processes sensor values and identifies which gesture has been performed.  
   -> A mapping is created between gestures and corresponding words/phrases.

3. **Output Generation**  
   -> The identified gesture is displayed as text on the 16x2 LCD.  
   -> Simultaneously, the APR audio module generates pre-recorded voice outputs.  
   -> A speaker is used for audio playback so others can hear the translated speech.

**Git 2nd Push Completed (2:30 PM) ** 


# Git Push 3 (Final Push)
Code Has Been Updated for the IoT Related tasks.  
Created A Block Digaram of the System for simple and Easy Understanding of the System.
Images of the system upladed in the repo.

Added IoT Based Functionalities Eg. 
1. Live Notification sharing to the Mobile through Blynk Cloud.
2. Easy and Simple Notifications (Blynk IoT App Notification and G-Mail)

Clicked Photos of the Working System & push in the Github Repo.

# Working of the System With Updated IoT Features

1. **Gesture Detection**
The MPU6050 sensor detects hand orientation and movement in terms of pitch, roll, and yaw angles.
Each specific gesture corresponds to predefined angle thresholds.
Example: Tilting the hand forward/backward/sideways represents different gestures.

2. **Data Processing**
The detected sensor values are sent to the NodeMCU ESP8266.
The microcontroller processes the raw data and identifies which gesture has been performed.
A gesture-to-word/phrase mapping is maintained, ensuring that each gesture translates to a meaningful output.

3. **Output Generation**
Once a gesture is identified:
The 16x2 LCD display shows the corresponding text.
The APR audio module plays the pre-recorded voice message.
The sound is output through a speaker for real-time speech translation.

4. **IoT Integration (Blynk Cloud + Gmail)**
The system is connected to the Blynk IoT Cloud via NodeMCU ESP8266.
When a gesture is detected:
A Blynk mobile notification is triggered, updating the user's smartphone instantly.
A Gmail alert is also sent, ensuring the gesture information can be received remotely.
This IoT feature makes the system more accessible, connected, and user-friendly, allowing gestures to be communicated even over long distances.


# Output of the system: 
1. Right --> Emergency
2. front --> Thank you
3. Back  --> I want medicine
4. left  --> i want water


# Group members: 
1. Nikhil Golait
2. Vedant Bhendkar
3. Akshad Gulhane

