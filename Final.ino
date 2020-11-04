#include <LiquidCrystal_I2C.h>       
LiquidCrystal_I2C lcd(0x27,16,2);
#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);

// Assigning pins
int buzzer = 13;
int GASA0 = A0;
int gasvalue;

// Intializing components
void setup() 
 {
 lcd.init();                       
 lcd.init();
 lcd.backlight(); 
 mySerial.begin(9600);
 Serial.begin(9600);
 pinMode(buzzer, OUTPUT); 
 }
  
// The main part of funcionality
void loop() 
  {
  int analogSensor = analogRead(GASA0);
  int gasvalue=(analogSensor-50)/10;
  Serial.println("Gas Level");
  Serial.println(gasvalue);
  lcd.setCursor(0,0);
  lcd.print("GAS Level:");
  lcd.setCursor(10,0);
  lcd.print(gasvalue);
  lcd.setCursor(12,0);
  lcd.print("%");
  
  // Checks if it has reached the threshold value
  if (gasvalue >= 15)
  {
    MakeCall();
    lcd.setCursor(0,1);
    lcd.print("DANGER");
    tone(buzzer, 1000, 200);
 
  }
  else
  {
  lcd.setCursor(0,1);
  lcd.print("NORMAL");
  noTone(buzzer);
  }
  delay(500);
  lcd.clear();
}
 void MakeCall()
{
  mySerial.println("ATD+919150450837;");  // Phone number to be called when leakage occurs
  Serial.println("Calling  ");
  delay(1000);
} 
