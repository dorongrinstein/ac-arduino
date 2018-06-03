#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int POWER_FROM_AC_CONTROLLER = 2; // to detect power coming in from A/C controller
//int on = 0; // off
const char ON_MESSAGE[] = "doron";
const char OFF_MESSAGE[] = "lisi";

// This is the transmitter code for the A/C condenser

RF24 radio(7,8);
const byte address[6] = "00001";


void setup() {
  //pinMode(13, OUTPUT);
  Serial.begin(9600);
  pinMode(POWER_FROM_AC_CONTROLLER, INPUT); 
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.stopListening();
}

void loop() {
  int on = digitalRead(POWER_FROM_AC_CONTROLLER);
  if (on) {
    Serial.print("The power is ON");
    radio.write(ON_MESSAGE, sizeof(ON_MESSAGE));
  } else {
       radio.write(OFF_MESSAGE, sizeof(OFF_MESSAGE));
    }
  
  delay(2000);
}
