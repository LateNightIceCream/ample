#include "cs42528.h"

void CS42528::begin() {
  begin(0b1001100);
}

void CS42528::begin(uint8_t address) {
  _address = address;
  _wire = &Wire;
}

void CS42528::begin(uint8_t address, TwoWire* the_wire) {
  _address = address;
  _wire = the_wire;
}

/*
  set memory access pointer (map) to register
*/
void CS42528::_write_map(cs42528_register_t reg, bool stop) {
  _wire->beginTransmission(_address);
  _wire->write((uint8_t)reg);
  _wire->endTransmission(stop);
}

uint8_t CS42528::read_register(cs42528_register_t reg) {
  
  _write_map(reg, true);
  
  _wire->requestFrom(_address, 1, true);
  
  while (!_wire->available()) {};
  
  return _wire->read();
}

void CS42528::write_register(cs42528_register_t reg, uint8_t data_byte) {

  _write_map(reg, false);

  _wire->write(data_byte);
  
  _wire->endTransmission();
  
}
