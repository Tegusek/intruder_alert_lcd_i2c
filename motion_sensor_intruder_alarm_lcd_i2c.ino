#include <LiquidCrystal_I2C.h> 

int ledPin = 13;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status

LiquidCrystal_I2C lcd(0x27,20,4); 

void setup() {
  lcd.init();   
  lcd.init();
  pinMode(inputPin, INPUT);     // declare sensor as input
 
  Serial.begin(9600);
}
 
void loop(){
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Interuder ");
  lcd.setCursor(0,1);
  lcd.print("detected! ");
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      lcd.clear();
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Standby");
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      lcd.clear();
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}
