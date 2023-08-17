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


uint8_t CS42528::set_register_bits(cs42528_register_t reg, uint8_t bits) {
  uint8_t current_value = read_register(reg);

  write_register(reg, current_value | bits);

  current_value = read_register(reg);

  return current_value;
}


uint8_t CS42528::unset_register_bits(cs42528_register_t reg, uint8_t bits) {

  uint8_t current_value = read_register(reg);

  write_register(reg, current_value & ~bits);

  current_value = read_register(reg);

  return current_value;
}


// BUG?: no error handling on read-only registers
uint8_t CS42528::get_register_defaults(cs42528_register_t reg) {
  return _register_defaults[reg];
}



// only holds those that you can actually write to
CS42528::RegDefaults CS42528::_register_defaults = { 
  
    { CS_REG_POWER_CONTROL, 0b10000001 },
    { CS_REG_FUNCTIONAL_MODE, 0b00000000 },
    { CS_REG_INTERFACE_FORMATS, 0b01000000 },
    { CS_REG_MISC_CONTROL, 0b00000000 },
    { CS_REG_CLOCK_CONTROL, 0b00000000 },
    { CS_REG_VOLUME_CONTROL, 0b00001000 },
    { CS_REG_CHANNEL_MUTE, 0b00000000 },
    { CS_REG_VOLUME_CONTROL_A1, 0b00000000 },
    { CS_REG_VOLUME_CONTROL_B1, 0b00000000 },
    { CS_REG_VOLUME_CONTROL_A2, 0b00000000 },
    { CS_REG_VOLUME_CONTROL_B2, 0b00000000 },
    { CS_REG_VOLUME_CONTROL_A3, 0b00000000 },
    { CS_REG_VOLUME_CONTROL_B3, 0b00000000 },
    { CS_REG_VOLUME_CONTROL_A4, 0b00000000 },
    { CS_REG_VOLUME_CONTROL_B4, 0b00000000 },
    { CS_REG_CHANNEL_INVERT, 0b00000000 },
    { CS_REG_MIXING_CTRL_PAIR_1, 0b00001001 },
    { CS_REG_MIXING_CTRL_PAIR_2, 0b00001001 },
    { CS_REG_MIXING_CTRL_PAIR_3, 0b00001001 },
    { CS_REG_MIXING_CTRL_PAIR_4, 0b00001001 },
    { CS_REG_ADC_LEFT_CH_GAIN, 0b00000000 },
    { CS_REG_ADC_RIGHT_CH_GAIN, 0b00000000 },
    { CS_REG_RCVR_MODE_CTRL, 0b00000000 },
    { CS_REG_RCVR_MODE_CTRL_2, 0b00000000 },
    { CS_REG_INTERRUPT_MASK, 0b00000000 },
    { CS_REG_INTERRUPT_MODE_MSB, 0b00000000 },
    { CS_REG_INTERRUPT_MODE_LSB, 0b00000000 },
    { CS_REG_BUFFER_CTRL, 0b01000000 },
    { CS_REG_RCVR_CS_DATA, 0b00000000 },
    { CS_REG_RCVR_ERRORS, 0b00000000 },
    { CS_REG_RCVR_ERRORS_MASK, 0b00000000 },
    { CS_REG_MUTEC, 0b00011111 },
    { CS_REG_RXP7_GPO7, 0b00000000 },
    { CS_REG_RXP6_GPO6, 0b00000000 },
    { CS_REG_RXP5_GPO5, 0b00000000 },
    { CS_REG_RXP4_GPO4, 0b00000000 },
    { CS_REG_RXP3_GPO3, 0b00000000 },
    { CS_REG_RXP2_GPO2, 0b00000000 },
    { CS_REG_RXP1_GPO1, 0b00000000 }
    
};  
