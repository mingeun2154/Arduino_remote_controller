//Sender
#include <Arduino.h>
#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

//RF module
RF24 radio(9,10);
const byte address[6]="00001"; //Address value must be same in sender and receiver
//button & led
int button_pin=2;
int led_pin=3;

void setup() {
  Serial.begin(9600);
  radio.begin();
  //RF module
  radio.openWritingPipe(address); //Set where to send data.
  radio.setPALevel(RF24_PA_MIN); //Set powerlevel.
  radio.stopListening(); //Set this module as sender.
  //button & led
  pinMode(button_pin, INPUT);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  if(digitalRead(button_pin)==HIGH){
    digitalWrite(led_pin, HIGH);
    const char msg[]="hello world";
    Serial.println("before send");
    radio.write(&msg, sizeof(msg));
    Serial.println(msg);
    delay(1000);
  }
  else
    digitalWrite(led_pin, LOW);
}