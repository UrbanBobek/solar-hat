int photo_res_1 = A0;
int photo_res_2 = A1;
int button_pin = 6;
void setup() {
  pinMode(photo_res_1, INPUT);
  pinMode(photo_res_2, INPUT);
  pinMode(button_pin, INPUT);


  Serial.begin(9600);

}

void loop() {
  float pr_val_1 = analogRead(photo_res_1);
  float pr_val_2 = analogRead(photo_res_2);
  
  Serial.print("Res1: ");Serial.print(calculate_rolling_average_1(pr_val_1)); Serial.print(" ");
  Serial.print("Res2: ");Serial.print(calculate_rolling_average_2(pr_val_2)); Serial.print(" ");
  Serial.println("");
  
  /*
  Serial.print("Res1: ");Serial.print(pr_val_1); Serial.print(" ");
  Serial.print("Res2: ");Serial.print(pr_val_2); Serial.print(" ");
  Serial.print("Diff: ");Serial.print(pr_val_2 - pr_val_1); Serial.print(" ");
  Serial.println("");
  */
}
