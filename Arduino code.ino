int dryValue = 1023;
int wetValue = 0;
int DryValuep = 0;
int WetValuep = 100;
int pump_pin=3;
int sensor=A3;
void setup() {
  Serial.begin(9600);
  pinMode(pump_pin,OUTPUT);
  pinMode(sensor,INPUT);
}
void loop() {
  int rawValue = analogRead(sensor);
  Serial.print("Raw: ");
  Serial.print(rawValue);
  Serial.print(" | ");
  
  int moiture = map(rawValue, dryValue, wetValue, DryValuep, WetValuep);
  
  Serial.print("Moiture content: ");
  Serial.print(moiture);
  Serial.println("%");
  delay(500);
  if(moiture<50)
  {
     Serial.print("pump is turned on");
     Serial.print(" | ");
     Serial.print("");
    digitalWrite(pump_pin,LOW);
    delay(5000);
 
    
   
    
    
  }
  else
  {
    Serial.print("Pump is turned off");
    Serial.print(" | ");
    Serial.print("");
    digitalWrite(pump_pin,HIGH);
    delay(5000);
    
  }
  
}
