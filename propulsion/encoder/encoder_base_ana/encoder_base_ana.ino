const uint8_t photo_transistor_pin_dx = A0;
const uint8_t photo_transistor_pin_sx = A1;
const int threshold = 700;

uint32_t dx_steps = 0;
uint32_t sx_steps = 0;

boolean dx_state_k = 1;
boolean dx_state_km1 = 1;
boolean sx_state_k = 1;
boolean sx_state_km1 = 1;
  
void setup() {
  Serial.begin(115200);
}

void loop() {
  int ana_value_dx = analogRead(photo_transistor_pin_dx);
  int ana_value_sx = analogRead(photo_transistor_pin_sx);

  sx_state_k = (ana_value_sx >= threshold)? 1: 0;
  dx_state_k = (ana_value_dx >= threshold)? 1: 0;
  
  if (dx_state_km1 != dx_state_k)
    dx_steps++;
    
  if (sx_state_km1 != sx_state_k)
    sx_steps++;
    
  Serial.print("sx_val: ");
  Serial.print(ana_value_sx);
  //Serial.print(" volt: ");
  //Serial.print(ana_value*0.0048);
  
  Serial.print(" st: ");
  Serial.print(sx_steps);
  Serial.print("\t\t\t\tdx_val: ");
  Serial.print(ana_value_dx);

  Serial.print(" st: ");
  Serial.println(dx_steps);

  dx_state_km1 = dx_state_k;
  sx_state_km1 = sx_state_k;  
}
