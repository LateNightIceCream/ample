#include "tsdp11.h"

void TSDP11::begin() {
  begin(0b1000100);
}

void TSDP11::begin(uint8_t address) {
  _address = address;
  _wire = &Wire;
}

void TSDP11::begin(uint8_t address, TwoWire* the_wire) {
  _address = address;
  _wire = the_wire;
}

/*
  set memory access pointer (map) to register
*/
void TSDP11::_write_map(tsdp11_register_t reg, bool stop) {
  _wire->beginTransmission(_address);
  _wire->write((uint8_t)reg);
  _wire->endTransmission(stop);
}

uint8_t TSDP11::read_register(tsdp11_register_t reg) {
  
  _write_map(reg, true);
  
  _wire->requestFrom(_address, 1, true);
  
  while (!_wire->available()) {};
  
  return _wire->read();
}

void TSDP11::write_register(tsdp11_register_t reg, uint8_t data_byte) {

  _write_map(reg, false);

  _wire->write(data_byte);
  
  _wire->endTransmission();
  
}
