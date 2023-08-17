#include <stdint.h>
#include <Wire.h>
#include "cs42528.h"
#include "tsdp11.h"
#include "bits.h"
#include <iomanip>

const int SDA_PIN = 21;
const int SCL_PIN = 22;

const int CODEC_ADDRESS = 0b1001100;
const int AMPLIFIER_ADDRESS = 0b1101000;

const int codec_rst_pin = 4;

CS42528* codec = new CS42528();
TSDP11* amplifier = new TSDP11();

void print_cs42528_regs();

void print_reg(CS42528* codec, const char* name, cs42528_register_t value);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(codec_rst_pin, OUTPUT);

  Wire.begin(SDA_PIN, SCL_PIN);

  Serial.println("Testing!!!");

  codec->begin(CODEC_ADDRESS);
  amplifier->begin(AMPLIFIER_ADDRESS);

  digitalWrite(codec_rst_pin, LOW);
  delay(200);
  digitalWrite(codec_rst_pin, HIGH);

  Serial.println(AMPLIFIER_ADDRESS, BIN);
  Serial.println(AMPLIFIER_ADDRESS, HEX);
  
  Serial.println("Done!!");

  /* init codec */

  // power control has to be set??

  // disable all DAC channels except channel 2 (AOUTA2, AOUTB2)
  //codec->set_register_bits(CS_REG_POWER_CONTROL, BIT1 | BIT3 | BIT4 | BIT5);

  // set pdn_rcvr to 00
  codec->unset_register_bits(CS_REG_POWER_CONTROL, BIT7 | BIT6);

  // high pass filter freeze
  // codec->set_register_bits(CS_REG_MISC_CONTROL, BIT2);

  // set OMCK clock to 24.5760 MHz (10)
  codec->set_register_bits(CS_REG_CLOCK_CONTROL, BIT5);
  codec->unset_register_bits(CS_REG_CLOCK_CONTROL, BIT4);

  // MCLK source = OMCK (manual) (01)
  codec->unset_register_bits(CS_REG_CLOCK_CONTROL, BIT2);
  codec->set_register_bits(CS_REG_CLOCK_CONTROL, BIT1);

  // auto-mute off
  codec->unset_register_bits(CS_REG_VOLUME_CONTROL, BIT3); 

  // mute SAI
  // codec->set_register_bits(CS_REG_VOLUME_CONTROL, BIT2); 

  // Volume PxA=B
  codec->set_register_bits(CS_REG_MIXING_CTRL_PAIR_2, BIT7);

  // set interrupt mask (activate all)
  codec->set_register_bits(CS_REG_INTERRUPT_MASK, BIT7 | BIT5 | BIT4 | BIT3 | BIT1 | BIT0);

  // set error mask (activate all)
  codec->set_register_bits(CS_REG_RCVR_ERRORS_MASK, BIT6 | BIT5 | BIT4 | BIT3 | BIT2 | BIT1 | BIT0);
  
  // mute polarity active high
  codec->set_register_bits(CS_REG_MUTEC, BIT5);

  // channel mutes select

  
  // power on codec
  codec->unset_register_bits(CS_REG_POWER_CONTROL, BIT0);

  // disable all DAC channels except channel 2 (AOUTA2, AOUTB2)
  // + disable ADC
  /*default_content = codec->get_register_defaults(CS_REG_POWER_CONTROL);
  temp = default_content | (BIT1 | BIT3 | BIT4 | BIT5);
  temp &= ~(BIT7 | BIT6);
  codec->write_register(CS_REG_POWER_CONTROL, temp);


  


  // Quad speed mode
  default_content = codec->get_register_defaults(CS_REG_FUNCTIONAL_MODE);
  // quad
  //temp = (default_content | BIT7) & ~BIT0;
  // single speed
  temp = (default_content) & ~(BIT7 | BIT6);
  codec->write_register(CS_REG_FUNCTIONAL_MODE, temp);

  // de-emphasis?

  // digital interface format?


  // fast roll-off
  default_content = codec->get_register_defaults(CS_REG_MISC_CONTROL);
  temp = default_content & ~BIT3;
  codec->write_register(CS_REG_MISC_CONTROL, temp);

  // clock control
  default_content = codec->get_register_defaults(CS_REG_CLOCK_CONTROL);
  // OMCK Frequency: 24.5760 MHz
  temp = (default_content | BIT5) & ~BIT4;
  // OMCK / PLL Auto-Switch
  //temp = temp | (BIT2 | BIT1);
  // OMCK
  temp = (temp | BIT1) & ~BIT2;
  codec->write_register(CS_REG_CLOCK_CONTROL, temp);

  // channel mute
  /*default_content = codec->get_register_defaults(CS_REG_CHANNEL_MUTE);
  temp = default_content | (BIT3 | BIT2);
  codec->write_register(CS_REG_CHANNEL_MUTE, temp);*/

  // MUTEC active high
  /*
  default_content = codec->get_register_defaults(CS_REG_MUTEC);
  temp = default_content | BIT5;
  // Testing
  temp &= ~(BIT0 | BIT1 | BIT2 | BIT3 | BIT4);
  codec->write_register(CS_REG_MUTEC, temp);

  // set LOCKM to 10
  default_content = codec->get_register_defaults(CS_REG_BUFFER_CTRL);
  // 10
  //temp = (default_content | BIT7) & ~BIT6;
  // 00
  temp = default_content & ~(BIT7 | BIT6);
  codec->write_register(CS_REG_BUFFER_CTRL, temp);

  // turn off auto-mute
  default_content = codec->get_register_defaults(CS_REG_VOLUME_CONTROL);
  temp = default_content & ~BIT3;
  codec->write_register(CS_REG_VOLUME_CONTROL, temp);

  // receiver mode control
  delay(200);

  default_content = codec->read_register(CS_REG_POWER_CONTROL);
  codec->write_register(CS_REG_POWER_CONTROL, default_content & ~BIT0);*/

  delay(1000);
  print_cs42528_regs(codec);

  delay(10000);
  print_cs42528_regs(codec);

  delay(20000);
  print_cs42528_regs(codec);

  
}

void loop() {
  // put your main code here, to run repeatedly:
}


void print_reg(CS42528* codec, const char* name, cs42528_register_t value) {

    const uint8_t min_width = 27;
    uint8_t default_value = codec->get_register_defaults(value);
    uint8_t current_value = codec->read_register(value);
    int name_len = strlen(name);
    
    //uint8_t current_value = codec->read_register(value);

    for (int i = 0; i < (min_width - name_len); i++) {
      Serial.print(' ');  
    }

    Serial.print(name);
    Serial.print("....");
    if (value < 0x10) {
        Serial.print("0"); 
    }
    Serial.print(value, HEX);
    Serial.print('h');
    Serial.print("....0b");
    //Serial.println(default_value, BIN);
    for (int i = 7; i >= 0; i--) {
      Serial.print(((uint16_t)default_value >> i) & (uint16_t)BIT0);
    }
    Serial.print("....0b");
    for (int i = 7; i >= 0; i--) {
      Serial.print(((uint16_t)current_value >> i) & (uint16_t)BIT0);
    }
    Serial.println();
}

void print_cs42528_regs(CS42528* codec) {

    print_reg(codec, "CS_REG_ID", CS_REG_ID);
    print_reg(codec, "CS_REG_POWER_CONTROL", CS_REG_POWER_CONTROL);
    print_reg(codec, "CS_REG_FUNCTIONAL_MODE", CS_REG_FUNCTIONAL_MODE);
    print_reg(codec, "CS_REG_INTERFACE_FORMATS", CS_REG_INTERFACE_FORMATS);
    print_reg(codec, "CS_REG_MISC_CONTROL", CS_REG_MISC_CONTROL);
    print_reg(codec, "CS_REG_CLOCK_CONTROL", CS_REG_CLOCK_CONTROL);
    print_reg(codec, "CS_REG_OMCL_PLL_CLK_RATIO", CS_REG_OMCL_PLL_CLK_RATIO);
    print_reg(codec, "CS_REG_RCVR_STATUS", CS_REG_RCVR_STATUS);
    print_reg(codec, "CS_REG_BURST_PREAMBLE_PC_0",CS_REG_BURST_PREAMBLE_PC_0);
    print_reg(codec, "CS_REG_BURST_PREAMBLE_PC_1", CS_REG_BURST_PREAMBLE_PC_1);
    print_reg(codec, "CS_REG_BURST_PREAMBLE_PD_0", CS_REG_BURST_PREAMBLE_PD_0);
    print_reg(codec, "CS_REG_BURST_PREAMBLE_PD_1",CS_REG_BURST_PREAMBLE_PD_1);
    print_reg(codec, "CS_REG_VOLUME_CONTROL",CS_REG_VOLUME_CONTROL);
    print_reg(codec, "CS_REG_CHANNEL_MUTE",CS_REG_CHANNEL_MUTE);
    print_reg(codec, "CS_REG_VOLUME_CONTROL_A1",CS_REG_VOLUME_CONTROL_A1);
    print_reg(codec, "CS_REG_VOLUME_CONTROL_B1",CS_REG_VOLUME_CONTROL_B1);
    print_reg(codec, "CS_REG_VOLUME_CONTROL_A2",CS_REG_VOLUME_CONTROL_A2);
    print_reg(codec, "CS_REG_VOLUME_CONTROL_B2",CS_REG_VOLUME_CONTROL_B2);
    print_reg(codec, "CS_REG_VOLUME_CONTROL_A3",CS_REG_VOLUME_CONTROL_A3);
    print_reg(codec, "CS_REG_VOLUME_CONTROL_B3",CS_REG_VOLUME_CONTROL_B3);
    print_reg(codec, "CS_REG_VOLUME_CONTROL_A4",CS_REG_VOLUME_CONTROL_A4);
    print_reg(codec, "CS_REG_VOLUME_CONTROL_B4",CS_REG_VOLUME_CONTROL_B4);
    print_reg(codec, "CS_REG_CHANNEL_INVERT",CS_REG_CHANNEL_INVERT);
    print_reg(codec, "CS_REG_MIXING_CTRL_PAIR_1",CS_REG_MIXING_CTRL_PAIR_1);
    print_reg(codec, "CS_REG_MIXING_CTRL_PAIR_2",CS_REG_MIXING_CTRL_PAIR_2);
    print_reg(codec, "CS_REG_MIXING_CTRL_PAIR_3",CS_REG_MIXING_CTRL_PAIR_3);
    print_reg(codec, "CS_REG_MIXING_CTRL_PAIR_4",CS_REG_MIXING_CTRL_PAIR_4);
    print_reg(codec, "CS_REG_ADC_LEFT_CH_GAIN",CS_REG_ADC_LEFT_CH_GAIN);
    print_reg(codec, "CS_REG_ADC_RIGHT_CH_GAIN",CS_REG_ADC_RIGHT_CH_GAIN);
    print_reg(codec, "CS_REG_RCVR_MODE_CTRL",CS_REG_RCVR_MODE_CTRL);
    print_reg(codec, "CS_REG_RCVR_MODE_CTRL_2",CS_REG_RCVR_MODE_CTRL_2);
    print_reg(codec, "CS_REG_INTERRUPT_STATUS",CS_REG_INTERRUPT_STATUS);
    print_reg(codec, "CS_REG_INTERRUPT_MASK",CS_REG_INTERRUPT_MASK);
    print_reg(codec, "CS_REG_INTERRUPT_MODE_MSB",CS_REG_INTERRUPT_MODE_MSB);
    print_reg(codec, "CS_REG_INTERRUPT_MODE_LSB",CS_REG_INTERRUPT_MODE_LSB);
    print_reg(codec, "CS_REG_BUFFER_CTRL",CS_REG_BUFFER_CTRL);
    print_reg(codec, "CS_REG_RCVR_CS_DATA",CS_REG_RCVR_CS_DATA);
    print_reg(codec, "CS_REG_RCVR_ERRORS",CS_REG_RCVR_ERRORS);
    print_reg(codec, "CS_REG_RCVR_ERRORS_MASK",CS_REG_RCVR_ERRORS_MASK);
    print_reg(codec, "CS_REG_MUTEC",CS_REG_MUTEC);
    print_reg(codec, "CS_REG_RXP7_GPO7",CS_REG_RXP7_GPO7);
    print_reg(codec, "CS_REG_RXP6_GPO6",CS_REG_RXP6_GPO6);
    print_reg(codec, "CS_REG_RXP5_GPO5",CS_REG_RXP5_GPO5);
    print_reg(codec, "CS_REG_RXP4_GPO4",CS_REG_RXP4_GPO4);
    print_reg(codec, "CS_REG_RXP3_GPO3",CS_REG_RXP3_GPO3);
    print_reg(codec, "CS_REG_RXP2_GPO2",CS_REG_RXP2_GPO2);
    print_reg(codec, "CS_REG_RXP1_GPO1",CS_REG_RXP1_GPO1);
    print_reg(codec, "CS_REG_Q_SUBCODE_0",CS_REG_Q_SUBCODE_0);
    print_reg(codec, "CS_REG_Q_SUBCODE_1",CS_REG_Q_SUBCODE_1);
    print_reg(codec, "CS_REG_Q_SUBCODE_2",CS_REG_Q_SUBCODE_2);
    print_reg(codec, "CS_REG_Q_SUBCODE_3",CS_REG_Q_SUBCODE_3);
    print_reg(codec, "CS_REG_Q_SUBCODE_4",CS_REG_Q_SUBCODE_4);
    print_reg(codec, "CS_REG_Q_SUBCODE_5",CS_REG_Q_SUBCODE_5);
    print_reg(codec, "CS_REG_Q_SUBCODE_6",CS_REG_Q_SUBCODE_6);
    print_reg(codec, "CS_REG_Q_SUBCODE_7",CS_REG_Q_SUBCODE_7);
    print_reg(codec, "CS_REG_Q_SUBCODE_8",CS_REG_Q_SUBCODE_8);
    print_reg(codec, "CS_REG_Q_SUBCODE_9",CS_REG_Q_SUBCODE_9);


}
