#include <Wire.h>

const int led_pin = 19;
const int pot_pin = 39;

const int SDA_PIN = 21;
const int SCL_PIN = 22;


const int CODEC_ADDRESS = 0b1001100;
const int AMPLIFIER_ADDRESS = 0b1000100;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Wire.begin(SDA_PIN, SCL_PIN);

  pinMode(led_pin, OUTPUT);
  pinMode(pot_pin, INPUT);

  Serial.println("Hello world");
  
}


void loop() {
  byte error, address;
  int num_devices = 0;
  
  Serial.println("Looking for I2C Devices");
  
  for(address = 1; address < 127; address++ ) {
    
    Wire.beginTransmission(address);
    
    error = Wire.endTransmission();
    
    if (error == 0) {
      
      Serial.print("I2C device found at address 0x");
      
      if (address < 16) {
        Serial.print("0");
      }
      
      Serial.println(address, HEX);
      
      num_devices++;
    }
    else if (error == 4) {
      Serial.print("Unknow error at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }    
  }
  
  if (num_devices == 0) {
    Serial.println("No I2C devices found\n");
  }
  else {
    Serial.println("done\n");
  }
  
  delay(5000);          
}
