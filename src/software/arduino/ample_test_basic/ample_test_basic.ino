
const int led_pin = 19;
const int pot_pin = 39; // SENSOR_VN

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(led_pin, OUTPUT);
  pinMode(pot_pin, INPUT);

  Serial.println("Hello world");
  
}

void loop() {

  int pot_voltage = analogRead(pot_pin);

  Serial.println(String(pot_voltage));

  if (pot_voltage > 4096 / 2) {
    digitalWrite(led_pin, HIGH);
  } else {
    digitalWrite(led_pin, LOW);
  }
  
  delay(10);
}
