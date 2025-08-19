#include <LiquidCrystal_I2C.h>
#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);
LiquidCrystal_I2C lcd (0x27, 16, 2); //
#define BLYNK_TEMPLATE_ID "TMPL3fv2wJ4xg"
#define BLYNK_TEMPLATE_NAME "Gesture to Speech Text Translator"
#define BLYNK_AUTH_TOKEN "lox6Ud4Kq2zOvJBtow9sbjI5oR_AA2FC"


int L1 = D0 ;
int L2 = D3;
int L3 = D4;
int L4 = D5;
int L5 = D6;
int L6 = D7;
// Your WiFi Credentials.
// Set password to "" for open networks.
char ssid[] = "Ucnwifi1";
char pass[] = "m1234567";
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
bool isconnected = false;
char auth[] = BLYNK_AUTH_TOKEN;

BlynkTimer timer;

void checkBlynkStatus() { // called every 2 seconds by SimpleTimer
  //getSensorData();
  isconnected = Blynk.connected();
  if (isconnected == true) {
    // digitalWrite(WIFI_LED, LOW);

    //Serial.println("Blynk Connected");
  }
  else {
    //digitalWrite(WIFI_LED, HIGH);
    Serial.println("Blynk Not Connected");
  }
}

void getSensorData()
{





}

void sendSensorData()
{



  //  else if(mpu6050.getAngleY()>15)
  //  {
  //     lcd. setCursor (0, 1);
  //  lcd. print ( "I Want Food " );
  // // Blynk.logEvent("fault1", "I Want Food");
  //
  //    digitalWrite(L5,0);
  //    delay(100);
  //    digitalWrite(L2,1);
  //    digitalWrite(L3,1);
  //   digitalWrite(L1,1);
  //   digitalWrite(L1,1);
  //   digitalWrite(L6,1);
  //  }


  //  else if(mpu6050.getAngleY()>15)
  //  {
  //     lcd. setCursor (0, 1);
  //  lcd. print ( "Hello " );
  // // Blynk.logEvent("fault1", "I Want Food");
  //
  //    digitalWrite(L6,0);
  //    delay(100);
  //    digitalWrite(L2,1);
  //    digitalWrite(L3,1);
  //   digitalWrite(L1,1);
  //   digitalWrite(L1,1);
  //   digitalWrite(L1,1);
  //  }










}

void setup()
{
  Serial.begin(9600);
  lcd. init ();
  lcd. backlight ();
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  pinMode(L6, OUTPUT);
  digitalWrite(L1, 0);
  //delay(100);
  digitalWrite(L2, 1);
  digitalWrite(L3, 1);
  digitalWrite(L4, 1);
  digitalWrite(L5, 1);
  digitalWrite(L6, 1);


  lcd. setCursor (0, 0);
  lcd. print ( "Gesture>Speech " );



  WiFi.begin(ssid, pass);
  timer.setInterval(2000L, checkBlynkStatus); // check if Blynk server is connected every 2 seconds
  Blynk.config(auth);
  delay(1000);
}

void loop()
{
  //sendSensorData();
  Blynk.run();
  timer.run();
  mpu6050.update();
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print("\tangleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print("\tangleZ : ");
  Serial.println(mpu6050.getAngleZ());

  if (mpu6050.getAngleX() > 45)
  { //Serial.print("1");

    Blynk.logEvent("medicine", "I Want Medicine");
    lcd. setCursor (0, 1);
    lcd. print ( "I Want Medicine " );

    Serial.println("I Want Medicine");
    digitalWrite(L5, 0);
    delay(1000);
    digitalWrite(L2, 1);
    digitalWrite(L3, 1);
    digitalWrite(L4, 1);
    digitalWrite(L1, 1);
    digitalWrite(L6, 1);
    digitalWrite(L5, 1);
    //delay(100);

  }
  else if (mpu6050.getAngleX() < -45)
  {
    Serial.println("Emergency");
    //Serial.print("2");

    Blynk.logEvent("emergency", "Emergency");
    lcd. setCursor (0, 1);
    lcd. print ( "Emergency        " );


    digitalWrite(L2, 0);
    delay(1000);
    digitalWrite(L1, 1);
    digitalWrite(L3, 1);
    digitalWrite(L4, 1);
    digitalWrite(L5, 1);
    digitalWrite(L6, 1);
    digitalWrite(L2, 1);
    delay(10);
  }
  else if (mpu6050.getAngleY() < -45)
  {
    Blynk.logEvent("thankyou", "Thank you");
    Serial.println("Thank you");
    lcd. setCursor (0, 1);
    lcd. print ( "Thank you      " );


    digitalWrite(L3, 0);
    delay(1000);
    digitalWrite(L2, 1);
    digitalWrite(L1, 1);
    digitalWrite(L4, 1);
    digitalWrite(L5, 1);
    digitalWrite(L6, 1);
    digitalWrite(L3, 1);
    delay(10);
  }
  else if (mpu6050.getAngleY() > 45)
  {
    // Blynk.logEvent("fault1", "I Want Water");
    lcd. setCursor (0, 1);
    lcd. print ( "I Want Water " );


    digitalWrite(L4, 0);
    delay(1000);
    digitalWrite(L2, 1);
    digitalWrite(L3, 1);
    digitalWrite(L1, 1);
    digitalWrite(L5, 1);
    digitalWrite(L6, 1);
    digitalWrite(L4, 1);
    delay(10);
  }

  else if (mpu6050.getAngleZ() > 45)
  {
    // Blynk.logEvent("fault1", "I Want Water");
    lcd. setCursor (0, 1);
    lcd. print ( "How Are You" );


    digitalWrite(L6, 0);
    delay(1000);
    digitalWrite(L2, 1);
    digitalWrite(L3, 1);
    digitalWrite(L1, 1);
    digitalWrite(L5, 1);
    digitalWrite(L6, 1);
    digitalWrite(L4, 1);
    delay(10);
  }

  else if (mpu6050.getAngleZ() < -45)
  {
    // Blynk.logEvent("fault1", "I Want Water");
    lcd. setCursor (0, 1);
    lcd. print ( "Turn ON Fan     " );


    digitalWrite(L1, 1);
    delay(1000);
    digitalWrite(L2, 1);
    digitalWrite(L3, 1);
    digitalWrite(L4, 1);
    digitalWrite(L5, 1);
    digitalWrite(L6, 1);
    digitalWrite(L1, 0);
    delay(50);
  }
  else
  {
    Serial.println("out");
    digitalWrite(L1, 1);
    //delay(100);
    digitalWrite(L2, 1);
    digitalWrite(L3, 1);
    digitalWrite(L4, 1);
    digitalWrite(L5, 1);
    digitalWrite(L6, 1);
    lcd. setCursor (0, 1);
    lcd. print ( "                      " );
  }

}
