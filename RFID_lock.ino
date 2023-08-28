#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(A0,A1,2,3,4,5);
int count = 0;
char c;
String id;
Servo myservo;

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  myservo.attach(6);
  myservo.write(0);
  pinMode(13, OUTPUT);
  pinMode(12,OUTPUT);
 lcd.setCursor(0,0);
 lcd.print("ENTER RFID_ID:");

}

void loop() {
  
  while(Serial.available()>0)
  {
    c = Serial.read();
    Serial.print(c);
   count++;
   id += c;
   //Serial.println(count);
   if(count == 10)  
    {
      
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("pass entered:");
      lcd.setCursor(0,1);
      lcd.print(id);
      delay(500);
     
      if(id=="ABC*12345*")  //Define valid tag id here
      {

        Serial.println();
        Serial.println("Valid TAG");
        lcd.setCursor(0,1);
        lcd.print("  Valid Tag  ");
        digitalWrite(12, HIGH);
        digitalWrite(13, LOW);
        delay(500);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("   Door Opened ");
        lcd.setCursor(0,1);
        lcd.print("Grn:ON | Red:OFF");
        myservo.write(180);
        delay(3000);
        myservo.write(0);  

      }

      else
      {

      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      Serial.println();
      Serial.println("Invalid TAG");
      lcd.setCursor(0,1);
      lcd.print(" InValid Tag ");
      delay(500);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("  Door Closed ");
      lcd.setCursor(0,1);
      lcd.print("Grn:OFF | Red:ON");
      myservo.write(0); 
      delay(3000);

      }

      count = 0;
      id="";
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("ENTER RFID_ID:");
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
    }

  }
  delay(500);
}