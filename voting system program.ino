#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const int cong = 2;
const int bjp = 3;
const int result = 4;
int state1 = 1;
int state2 = 1;
int state3 = 1;
int congcount = 0;
int bjpcount = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  lcd.init();
  lcd.backlight();
  pinMode(cong, INPUT_PULLUP);
  pinMode(bjp, INPUT_PULLUP);
  pinMode(result, INPUT_PULLUP);
  lcd.print("welcome to voting");
}

void loop() {

  state1 = digitalRead(cong);
  state2 = digitalRead(bjp);
  state3 = digitalRead(result);

  if (state1 == LOW) {
    lcd.clear();
    congcount = congcount + 1;
    // lcd.print("cong count =");
    // lcd.print(congcount);
    lcd.print("vote added");
    delay(1000);
    lcd.clear();
  }

  if (state2 == LOW) {
    lcd.clear();
    bjpcount = bjpcount + 1;
    // lcd.print("bjp count= ");
    // lcd.print(bjpcount);

    lcd.print("vote added");
    delay(1000);
    lcd.clear();
  }

  if (state3 == LOW) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("cong count= ");
    lcd.print(congcount);

    lcd.setCursor(0, 1);
    lcd.print("bjp count= ");
    lcd.print(bjpcount);
    delay(5000);
    lcd.clear();
    if (bjpcount > congcount) {
      lcd.print("bJP WIN");
    } else if (bjpcount == congcount) {
      lcd.print("match tie");
    } else {
      lcd.print("CONG WIN");
    }
  }
}
