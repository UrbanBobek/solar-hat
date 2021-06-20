const int num_of_readings = 20;

float calculate_rolling_average_1(float analog_val){
  static int readings[num_of_readings];  
  
  static int index = 0;                  
  static long total = 0;                      

  // subtract the last reading:
  total = total - readings[index];
        
  // read from the sensor:  
  readings[index] = analog_val; 
  
  // add the reading to the total:
  total= total + readings[index];      
   
  // advance to the next position in the array:  
  index = index + 1;                    

  // if we're at the end of the array...
  if (index >= num_of_readings)              
    // ...wrap around to the beginning: 
    index = 0;                           

  // calculate the average:
  float average = total / num_of_readings;  
  
  return average;
}

float calculate_rolling_average_2(float analog_val){
  static int readings[num_of_readings];  
  
  static int index = 0;                  
  static long total = 0;                      

  // subtract the last reading:
  total = total - readings[index];
        
  // read from the sensor:  
  readings[index] = analog_val; 
  
  // add the reading to the total:
  total= total + readings[index];      
   
  // advance to the next position in the array:  
  index = index + 1;                    

  // if we're at the end of the array...
  if (index >= num_of_readings)              
    // ...wrap around to the beginning: 
    index = 0;                           

  // calculate the average:
  float average = total / num_of_readings;  
  
  return average;
}
