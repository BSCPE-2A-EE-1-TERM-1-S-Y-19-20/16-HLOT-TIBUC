#include <Wire.h>

double pulse, frequency, capacitance, inductance, inductance_mH;
void setup(){
 
  Serial.begin(9600);
  pinMode(11, INPUT);
  pinMode(13, OUTPUT);
  
  Serial.println("INDUCTANCE METER");
  delay(1000);
  
}
void loop(){
  digitalWrite(13, HIGH); 
  delay(5);
  digitalWrite(13,LOW);
  delayMicroseconds(100); 
  pulse = pulseIn(11,HIGH,5000);
  if(pulse > 0.1){ 
    
  capacitance = 1.E-6; 
  
  frequency = 1.E6/(2*pulse);
  inductance = 1./(capacitance*frequency*frequency*4.*3.14159*3.14159);
  inductance *= 1E6; //note that this is the same as saying inductance = inductance*1E6
  inductance_mH = inductance/1000; 
  
  
  Serial.print("High for uS:");
  Serial.print( pulse );
  Serial.print("\tinductance uH:");
  Serial.println( inductance );
  delay(10);


  }
}
