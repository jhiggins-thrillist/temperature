#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include "RF24/RPi/RF24/RF24.h"

int main() {
  float msg[1];
  RF24 radio(RPI_V2_GPIO_P1_15, RPI_V2_GPIO_P1_24, BCM2835_SPI_SPEED_8MHZ);
  const uint64_t address = 0xE8E8F0F0E1LL;

  radio.begin();
  radio.setPayloadSize(4);
  radio.openReadingPipe(1, address);
  radio.startListening();

  while (true) {

    if (radio.available()) {
       radio.read(&msg, 1); 

       float theChar = msg[0];

       printf("%f", theChar);
       return 1;

     } else {
       //printf("nothing");
     }

  }

}


