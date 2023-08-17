#include <stdint.h>
#include <Wire.h>
#include <map>

enum cs42528_register_t {
  
  CS_REG_ID = 0x01,
  CS_REG_POWER_CONTROL,
  CS_REG_FUNCTIONAL_MODE,
  CS_REG_INTERFACE_FORMATS,
  CS_REG_MISC_CONTROL,
  CS_REG_CLOCK_CONTROL,
  CS_REG_OMCL_PLL_CLK_RATIO,
  CS_REG_RCVR_STATUS,
  CS_REG_BURST_PREAMBLE_PC_0,
  CS_REG_BURST_PREAMBLE_PC_1,
  CS_REG_BURST_PREAMBLE_PD_0,
  CS_REG_BURST_PREAMBLE_PD_1,
  CS_REG_VOLUME_CONTROL,
  CS_REG_CHANNEL_MUTE,
  CS_REG_VOLUME_CONTROL_A1,
  CS_REG_VOLUME_CONTROL_B1,
  CS_REG_VOLUME_CONTROL_A2,
  CS_REG_VOLUME_CONTROL_B2,
  CS_REG_VOLUME_CONTROL_A3,
  CS_REG_VOLUME_CONTROL_B3,
  CS_REG_VOLUME_CONTROL_A4,
  CS_REG_VOLUME_CONTROL_B4,
  CS_REG_CHANNEL_INVERT,
  CS_REG_MIXING_CTRL_PAIR_1,
  CS_REG_MIXING_CTRL_PAIR_2,
  CS_REG_MIXING_CTRL_PAIR_3,
  CS_REG_MIXING_CTRL_PAIR_4,
  CS_REG_ADC_LEFT_CH_GAIN,
  CS_REG_ADC_RIGHT_CH_GAIN,
  CS_REG_RCVR_MODE_CTRL,
  CS_REG_RCVR_MODE_CTRL_2,
  CS_REG_INTERRUPT_STATUS,
  CS_REG_INTERRUPT_MASK,
  CS_REG_INTERRUPT_MODE_MSB,
  CS_REG_INTERRUPT_MODE_LSB,
  CS_REG_BUFFER_CTRL,
  CS_REG_RCVR_CS_DATA,
  CS_REG_RCVR_ERRORS,
  CS_REG_RCVR_ERRORS_MASK,
  CS_REG_MUTEC,
  CS_REG_RXP7_GPO7,
  CS_REG_RXP6_GPO6,
  CS_REG_RXP5_GPO5,
  CS_REG_RXP4_GPO4,
  CS_REG_RXP3_GPO3,
  CS_REG_RXP2_GPO2,
  CS_REG_RXP1_GPO1,
  CS_REG_Q_SUBCODE_0,
  CS_REG_Q_SUBCODE_1,
  CS_REG_Q_SUBCODE_2,
  CS_REG_Q_SUBCODE_3,
  CS_REG_Q_SUBCODE_4,
  CS_REG_Q_SUBCODE_5,
  CS_REG_Q_SUBCODE_6,
  CS_REG_Q_SUBCODE_7,
  CS_REG_Q_SUBCODE_8,
  CS_REG_Q_SUBCODE_9,
  
};


const uint8_t cs4258_default_contents[8] = {1, 2, 3, 4};




class CS42528 {

  private:
    TwoWire* _wire;
    uint8_t _address;
    uint8_t _volume_byte;
    
    typedef std::map<cs42528_register_t, uint8_t> RegDefaults;
    static RegDefaults _register_defaults;
    
    void _write_map(cs42528_register_t reg, bool stop);
    
  public:

    uint8_t abc;
  
    CS42528() {}
    ~CS42528() {}

    void begin();
    void begin(uint8_t address);
    void begin(uint8_t address, TwoWire* the_wire);
    
    uint8_t read_register(cs42528_register_t reg);
    
    void write_register(cs42528_register_t reg, uint8_t data_byte);

    uint8_t get_register_defaults(cs42528_register_t reg);
    
    //void set_volume(float percentage);

    uint8_t set_register_bits(cs42528_register_t reg, uint8_t bits);
    uint8_t unset_register_bits(cs42528_register_t reg, uint8_t bits);
};
