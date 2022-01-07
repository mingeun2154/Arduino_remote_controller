//Sender
#include <Arduino.h>
#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

#define ON "on"//right
#define OFF "off"//left

//RF module
RF24 radio(9,10);
const byte address[6]="00001"; //Address value must be same in sender and receiver
//buttons
int button_on=3;
int button_off=4;

void setup() {
  Serial.begin(9600);
  radio.begin();
  //RF module
  radio.openWritingPipe(address); //Set where to send data.
  radio.setPALevel(RF24_PA_MIN); //Set powerlevel.
  radio.stopListening(); //Set this module as sender.
  //button & led
  pinMode(button_on, INPUT);
  pinMode(button_off, INPUT);
}

void loop() {
  const char signal[]="";
  if(digitalRead(button_on)==HIGH){
    const char signal[]="on";
    radio.write(&signal, sizeof(signal));
    Serial.println(signal);
    delay(500);
  }
  else if(digitalRead(button_off)==HIGH){
    const char signal[]="off";
    radio.write(&signal, sizeof(signal));
    Serial.println(signal);
    delay(500);
  }
  else{
    Serial.println("waiting...");
  }
}