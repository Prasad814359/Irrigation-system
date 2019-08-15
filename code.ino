int dryValue = 1023; // maximum raw value given by FC-28 sensor
int wetValue = 0;    //minimum raw value given by FC-28 sensor
int DryValuep = 0;  // to map in terms of percentage
int WetValuep = 100;
int pump_pin=8;    //Digital pin

void setup() {
  Serial.begin(9600);
  pinMode(pump_pin,OUTPUT);
}


void loop() {
  int rawValue = analogRead(A4); //Reading the raw data from FC-28
  Serial.print("Raw: ");
  Serial.print(rawValue);
  Serial.print(" | ");
  
  int moiture = map(rawValue, dryValue, wetValue, DryValuep, WetValuep);  //mapping the raw data in terms of percentage
  
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
