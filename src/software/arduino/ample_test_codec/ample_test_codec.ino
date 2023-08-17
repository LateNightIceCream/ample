#include <stdint.h>
#include <Wire.h>
#include "cs42528.h"

const int SDA_PIN = 21;
const int SCL_PIN = 22;

cs42528_register_t abc = CS_REG_RXP5_GPO5;

const int CODEC_ADDRESS = 0b1001100;
const int AMPLIFIER_ADDRESS = 0b1000100;

CS42528* codec = new CS42528();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(abc, HEX);

  Wire.begin(SDA_PIN, SCL_PIN);

  Serial.println("Testing!!!");
  codec->begin(CODEC_ADDRESS);
  Serial.println(codec->read_register(CS_REG_CHANNEL_MUTE), BIN);
  codec->write_register(CS_REG_CHANNEL_MUTE, 0b00000001);
  Serial.println(codec->read_register(CS_REG_CHANNEL_MUTE), BIN);
  Serial.println("Done!!");
}

void loop() {
  // put your main code here, to run repeatedly:

}
