# EVO-DEVELOPERS_HTH_2k25

## ReadME File (Created)

# Problem Statement Title with ID:

# Problem Statement: 
**Gesture-to-Speech Translator**

# ID : 
**HTH_22**


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

# Group members: 

1. Nikhil Golait
2. Vedant Bhendkar
3. Akshad Gulhane



