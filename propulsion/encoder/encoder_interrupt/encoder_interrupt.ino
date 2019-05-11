const uint8_t photo_transistor_pin_dx = 2;
const uint8_t photo_transistor_pin_sx = 3;

volatile uint32_t dx_steps = 0;
volatile uint32_t sx_steps = 0;
  
void setup() {
  pinMode(photo_transistor_pin_dx, INPUT_PULLUP);
  pinMode(photo_transistor_pin_sx, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(photo_transistor_pin_dx), update_encoder_dx, RISING);
  attachInterrupt(digitalPinToInterrupt(photo_transistor_pin_sx), update_encoder_sx, RISING);
  Serial.begin(115200);
}

void loop() {
      
  Serial.print("sx_val: ");
  Serial.print(sx_steps);
  Serial.print("\t\t\t\tdx_val: ");
  Serial.println(dx_steps);
}

// ISR 
void update_encoder_sx() {
    sx_steps++;
}

//ISR
void update_encoder_dx() {
    dx_steps++;
}
