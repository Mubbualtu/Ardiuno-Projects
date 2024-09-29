#include<stdio.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);

const int entry=8;
const int exit1=9;
const int  ledg=2;
const int ledr=3;
const int buzzerPin = 4;
 int count=0;
 int entrystate=1;
 int exitstate=1;
 int z=0;


void setup() {
  pinMode(entry,INPUT_PULLUP);
  pinMode(exit1,INPUT_PULLUP);
  pinMode(ledr,OUTPUT);
   pinMode(ledg,OUTPUT);
  	lcd.init();
	lcd.backlight();
}

void loop() {
  entrystate=digitalRead(entry);
  exitstate=digitalRead(exit1);

  if (entrystate==LOW){
    count=count+1;
    lcd.print("enrty count=");
    lcd.print(count);
    tone(buzzerPin, 2000);
  if(entrystate == LOW)
    {
      digitalWrite(ledg,HIGH);
    }
     noTone(buzzerPin);
    lcd.clear();
  }


  if(exitstate == LOW){
    count=count-1;
    lcd.print("exit count=");
    lcd.print(count);
     tone(buzzerPin, 2000);
    if(exitstate == LOW)
    {
      digitalWrite(ledr,HIGH);
    }
        noTone(buzzerPin);
    lcd.clear();
  }

 if(exitstate == HIGH)
    {
      digitalWrite(ledr,LOW);
      digitalWrite(ledg,LOW);
    }

    else{
      lcd.clear();
    }

}
