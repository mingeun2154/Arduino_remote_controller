//remote controller
#include <Arduino.h>
#include <IRremote.h>

int sendPin=3;
bool LEDFeedback = true;

IRsend irsend(sendPin);
IRData ON{};
IRData OFF{};

void setup() {
  Serial.begin(9600);
  //IRremote set
  irsend.begin(LEDFeedback);
  irsend.enableIROut(30);
  ON.protocol=LG;
  ON.command=0x880628;
  OFF.protocol=LG;
  OFF.command=0x88C0051;
  //pinMode set
  pinMode(10, INPUT);
}

void loop() {
  if(digitalRead(10)==HIGH){
    irsend.send
    Serial.print("signal");
    delay(500);
  }
  digitalWrite(sendPin, LOW);
}