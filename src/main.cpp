//remote controller
#include <Arduino.h>
#include <IRremote.h>

int sendPin=3;
int buttonPin=10;

//turn on main light
IRsend irsend_main_on;
IRData irdata_main_on{LG, 0x88, 0xC005, 0, 0x1C, 0x80, 0x88C051, nullptr};

//turn off main light
IRsend main_off;
IRData irdata_main_off;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  //IRSend set
  irsend_main_on.begin(sendPin, false);
  irsend_main_on.write(&irdata_main_on);
  irsend_main_on.enableIROut(38);
}

void loop() {
  if(digitalRead(buttonPin)==HIGH){
    irsend_main_on.sendLG(irdata_main_on.address, irdata_main_on.command, 0);
    Serial.print("turn on\n");
    delay(500);
  }
}