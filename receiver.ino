#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// receiver code for A/C condenser

const char ON_MESSAGE[] = "doron";
const char OFF_MESSAGE[] = "lisi";

RF24 radio(7,8);

const byte address[6] = "00001";

void setup() {
  pinMode(9, OUTPUT); // for LED
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();

}

void loop() {
  char text[32] = "";
  if (radio.available()) {
    radio.read(&text, sizeof(text));
    String transData = String(text);
    if (transData == ON_MESSAGE) {
      digitalWrite(9, HIGH);
    }
    if (transData == OFF_MESSAGE) {
      digitalWrite(9, LOW);
    }
    
  }

}
