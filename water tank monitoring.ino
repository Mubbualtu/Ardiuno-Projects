const int BUTTON1 = 12;
const int BUTTON2 = 13;
const int LED1 = 5;
const int LED2 = 6;
const int LED3 = 7;
int state1 = 0;
int state2 = 0;

void setup() {
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  state1 = digitalRead(BUTTON1);
  state2 = digitalRead(BUTTON2);

  if (state1 == 1 && state2 == 1) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);

  } 
  else if (state1 == 0 && state2 == 1) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
  }
  else if (state1 == 0 && state2 == 0) {
    digitalWrite(LED3, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED1, LOW);
  }
}
