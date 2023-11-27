#define MAX_PWM 254
#define PIN_PWM 3   // PWM to control piston
#define PIN_MOD 4   // Mode of piston, controls if it's forwards or backwards 

// Makes piston go forwards
// @param perc: percentage of PWM, from 0 to 100. Controls the speed of piston
void pistFw(uint8_t perc){
  // Prevent values beyond 100%
  if(perc > 100) perc = 100;
  digitalWrite(PIN_MOD, HIGH);    // TODO: Until trials, supouse HIGH is FW

  analogWrite(PIN_PWM, (uint8_t)(perc*MAX_PWM/100));
}


// Makes piston go backwards
// @param perc: percentage of PWM, from 0 to 100. Controls the speed of piston
void pistBw(uint8_t perc){
  // Prevent values beyond 100%
  if(perc > 100) perc = 100;
  digitalWrite(PIN_MOD, LOW);   // TODO: Until trials, supouse LOW is BW

  analogWrite(PIN_PWM, (uint8_t)(perc*MAX_PWM/100));
}


void setup() {
  
  // Pins D3 and D11 - 62.5 kHz
  TCCR2B = 0b00000001; // x1
  TCCR2A = 0b00000011; // fast pwm
  
  pinMode(PIN_PWM, OUTPUT);
  pinMode(PIN_MOD, OUTPUT);
}

void loop() {

  // 50% of PWM
  pistFw(50);
  delay(5000);
  pistBw(50);
  delay(5000);

  // 100% of PWM
  pistFw(100);
  delay(5000);
  pistBw(100);
  delay(5000);

  // 25% of PWM
  pistFw(25);
  delay(5000);
  pistBw(25);
  delay(5000);

}
