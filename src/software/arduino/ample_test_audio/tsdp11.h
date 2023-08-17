#include <stdint.h>
#include <Wire.h>

enum tsdp11_register_t {

  TSDP11_REG_DEVADD0 = 0x00,
  TSDP11_REG_DEVID,
  TSDP11_REG_DEVREV,
  TSDP11_REG_STATUS_0,
  TSDP11_REG_STATUS_1,
  TSDP11_REG_CP_CTRL1L,
  TSDP11_REG_CP_CTRL2,
  TSDP11_REG_VREG_CP_CTRL,
  TSDP11_REG_VDDA_SENSE_CTRL,
  TSDP11_REG_CLSH_SENSE_CTRL1,
  TSDP11_REG_CLSH_SENSE_CTRL2,
  TSDP11_REG_HI_CUR_CTRL1,
  TSDP11_REG_HI_CUR_CTRL2,
  TSDP11_REG_CP_SCUR_CTRL1,
  TSDP11_REG_CP_SCUR_CTRL2,
  TSDP11_REG_CP_REG_CTRL1,
  TSDP11_REG_CP_REG_CTRL2,
  TSDP11_REG_HDPH_CTRL1,
  TSDP11_REG_HDPH_CTRL2,
  TSDP11_REG_HDPH_CTRL3,
  TSDP11_REG_HDPH_CTRL4,
  TSDP11_REG_SELF_OSC_CTRL1,
  TSDP11_REG_SELF_OSC_CTRL2,
  TSDP11_REG_BIASG_CTRL1,
  TSDP11_REG_BIASG_CTRL2,
  TSDP11_REG_REF_SUP_CTRL,
  TSDP11_REG_BANGAP_CTRL,
  TSDP11_REG_TEMP_SENSE_CTRL1,
  TSDP11_REG_TEMP_SENSE_CTRL2,
  TSDP11_REG_PAD_CTRL,
  TSDP11_REG_SHUTDOWN

};

class TSDP11 {

  private:
    TwoWire* _wire;
    uint8_t _address;
    
    void _write_map(tsdp11_register_t reg, bool stop);
    
  public:
  
    TSDP11() {}
    ~TSDP11() {}

    void begin();
    void begin(uint8_t address);
    void begin(uint8_t address, TwoWire* the_wire);
    
    uint8_t read_register(tsdp11_register_t reg);
    void write_register(tsdp11_register_t reg, uint8_t data_byte);
};
