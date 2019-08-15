int dryValue = 1023;
int wetValue = 0;
int DryValuep = 0;
int WetValuep = 100;
int pump_pin=8;
void setup() {
  Serial.begin(9600);
  pinMode(pump_pin,OUTPUT);
}
void loop() {
  int rawValue = analogRead(A4);
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
     Serial.print("pump is turned On");
     Serial.print("");
    digitalWrite(pump_pin,HIGH);
    delay(2000);
  }
  else
  {
    digitalWrite(pump_pin,LOW);
    
  }
  
}
