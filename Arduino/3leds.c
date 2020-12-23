//define constants and variables
const int sensorPin = A0;
const float baselineTemp = 15.0;

void setup() {
  Serial.begin(9600); // opens a serial communication
  
}

void loop(){
  int pinNumber, sensorVal;
  sensorVal = analogRead(sensorPin); // reads a analog port
  for(pinNumber = 2; pinNumber <= 4; pinNumber++) {
  	pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
  
  float voltage = ((sensorVal / 1024.0) * 5.0);
  float temperature = ((voltage - 0.5) * 100);
  
  // Low
  if(temperature <= baselineTemp) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else {
    // Medium
    if((temperature > baselineTemp) && 
       (temperature < baselineTemp+55)) {
     		digitalWrite(2, LOW);
    		digitalWrite(3, HIGH);
    		digitalWrite(4, LOW);
    } else {
      // High
      		digitalWrite(2, LOW);
    		digitalWrite(3, LOW);
    		digitalWrite(4, HIGH);
    }
  }
  Serial.print("Valor do sensor: ");
  Serial.print(sensorVal);
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  Serial.print(temperature);
  Serial.print("\n");
}