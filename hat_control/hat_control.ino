int photo_res_1 = A0;
int photo_res_2 = A1;
short button_pin = 6;
short H_bridge_1A = 9;
short H_bridge_1B = 8;

boolean turn_flag = false;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50; 
bool button_state = false;
int last_button_reading = 0;

int dead_band = 30;

void setup() {
  pinMode(photo_res_1, INPUT);
  pinMode(photo_res_2, INPUT);
  pinMode(button_pin, INPUT);
  
  pinMode(H_bridge_1A, OUTPUT);
  pinMode(H_bridge_1B, OUTPUT);
  digitalWrite(H_bridge_1A, LOW);
  digitalWrite(H_bridge_1B, LOW);

  Serial.begin(9600);
}

void loop() {
  float pr_val_1 = analogRead(photo_res_1);
  float pr_val_2 = analogRead(photo_res_2);

  float pr_1 = calculate_rolling_average_1(pr_val_1);
  float pr_2 = calculate_rolling_average_2(pr_val_2);
  float pr_diff = pr_1 - pr_2;
  
  Serial.print("Res1: ");Serial.print(pr_1); Serial.print(" ");
  Serial.print("Res2: ");Serial.print(pr_2); Serial.print(" ");
  Serial.print("diff: ");Serial.print(pr_diff); Serial.print(" ");
  Serial.println("");

  int button_reading = digitalRead(button_pin);
  

  
   // If the switch changed, due to noise or pressing:
  if (button_reading != last_button_reading) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (button_reading != button_state) {
      button_state = button_reading;

      if (button_state == HIGH) {
        turn_flag = !turn_flag;
      }
    }
  }
  last_button_reading = button_reading;


  // Control logic
  if(abs(pr_diff) > dead_band){
    if(pr_diff > 0){
      Serial.println("turn right");
    }  
    else{  
      Serial.println("turn left");
    }
  }
  
  if(turn_flag){

    bool turn_direction = true;
    
    // turn counter-clockwise
    if(turn_direction){
      digitalWrite(H_bridge_1A, HIGH);  
      digitalWrite(H_bridge_1B, LOW);
    }
    // turn clockwise
    else{
      digitalWrite(H_bridge_1A, LOW);  
      digitalWrite(H_bridge_1B, HIGH);
    }
  }
  else{
    digitalWrite(H_bridge_1A, LOW);
    digitalWrite(H_bridge_1B, LOW);
  }



  
}
