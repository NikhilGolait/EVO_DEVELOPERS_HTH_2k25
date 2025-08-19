#include <LiquidCrystal_I2C.h>
#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);
LiquidCrystal_I2C lcd (0x27, 16, 2);

// LED Pins
int L1 = D0;
int L2 = D3;
int L3 = D4;
int L4 = D5;
int L5 = D6;
int L6 = D7;

void setup() {
  Serial.begin(9600);
  
  // LCD init
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Gesture > Text");
  lcd.setCursor(0, 1);
  lcd.print("HTH-22");

  // MPU6050 init
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

  // LED pins
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  pinMode(L6, OUTPUT);

  // Turn OFF all LEDs at start
  digitalWrite(L1, HIGH);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, HIGH);
  digitalWrite(L4, HIGH);
  digitalWrite(L5, HIGH);
  digitalWrite(L6, HIGH);
}

void loop() {
  mpu6050.update();

  Serial.print("X: "); Serial.print(mpu6050.getAngleX());
  Serial.print("\tY: "); Serial.print(mpu6050.getAngleY());
  Serial.print("\tZ: "); Serial.println(mpu6050.getAngleZ());

  if (mpu6050.getAngleX() > 45) {
    lcd.setCursor(0, 1);
    lcd.print("I Want Medicine ");
    Serial.println("I Want Medicine");
    digitalWrite(L5, LOW);
    delay(1000);
    allLedsOff();
  }
  else if (mpu6050.getAngleX() < -45) {
    lcd.setCursor(0, 1);
    lcd.print("Emergency       ");
    Serial.println("Emergency");
    digitalWrite(L2, LOW);
    delay(1000);
    allLedsOff();
  }
  else if (mpu6050.getAngleY() < -45) {
    lcd.setCursor(0, 1);
    lcd.print("Thank You       ");
    Serial.println("Thank You");
    digitalWrite(L3, LOW);
    delay(1000);
    allLedsOff();
  }
  else if (mpu6050.getAngleY() > 45) {
    lcd.setCursor(0, 1);
    lcd.print("I Want Water    ");
    Serial.println("I Want Water");
    digitalWrite(L4, LOW);
    delay(1000);
    allLedsOff();
  }
  else if (mpu6050.getAngleZ() > 45) {
    lcd.setCursor(0, 1);
    lcd.print("How Are You     ");
    Serial.println("How Are You");
    digitalWrite(L6, LOW);
    delay(1000);
    allLedsOff();
  }
  else if (mpu6050.getAngleZ() < -45) {
    lcd.setCursor(0, 1);
    lcd.print("Turn ON Fan     ");
    Serial.println("Turn ON Fan");
    digitalWrite(L1, LOW);
    delay(1000);
    allLedsOff();
  }
  else {
    lcd.setCursor(0, 1);
    lcd.print("                "); // clear line
    allLedsOff();
  }
}

// Function to switch OFF all LEDs
void allLedsOff() {
  digitalWrite(L1, HIGH);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, HIGH);
  digitalWrite(L4, HIGH);
  digitalWrite(L5, HIGH);
  digitalWrite(L6, HIGH);
}
