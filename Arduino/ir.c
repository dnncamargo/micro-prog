#include <IRremote.h>
#define POWER 16580863

/* Pinos 
*	Pino 3: Receptor Infravermelho
*	Pino 4: Led
*/
const int PIN_IR_RECEPT = 3;
const int PIN_RED_LED = 4;
bool STATUS_TURNON = false;

IRrecv receptor(PIN_IR_RECEPT); // Receptor IR
decode_results outputIR;

void setup(){
  Serial.begin(9600);
  pinMode(PIN_RED_LED, OUTPUT);
  receptor.enableIRIn();
}

void loop(){
  if (receptor.decode(&outputIR)) {
    switch(outputIR.value){
      case POWER:
        STATUS_TURNON = !STATUS_TURNON;
        digitalWrite(PIN_RED_LED, STATUS_TURNON);
      	
      break;
    }   receptor.resume(); // recebe o valor
  }
  delay(100); // Aguarda 100 milisegundos
}

// light 


//const int threshold = 150;
//int light_level;
//loop
  /*light_level = analogRead(PIN_LDR);
  if (light_level < threshold) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }*/

//motor loop
  digitalWrite(Pino1A, HIGH);
  digitalWrite(Pino2A, LOW);
  digitalWrite(PIN_L293D, HIGH);
  delay(3000);
  digitalWrite(PIN_L293D, LOW);
  delay(2000);
  digitalWrite(Pino1A, LOW);
  digitalWrite(Pino2A, HIGH);
  digitalWrite(PIN_L293D, HIGH);
  delay(3000);
  digitalWrite(PIN_L293D, LOW);
  delay(2000);

    // Turn on the LED if the object is too close:
  if(cm0 < 100) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
  
  // Turn on the LED if the object is too close:
  if(cm1 < 100) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }