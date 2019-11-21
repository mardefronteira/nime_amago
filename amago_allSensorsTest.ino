// ECG
#define ecgOUT A2
#define ecgMinus 2
#define ecgPlus 3
unsigned long lastEcg = 0;
int ecgReading;

// Wind
#define windRV A0
#define windTMP A1
unsigned long lastWind = 0;
int windRvReading;
int windTmpReading;

void setup() {
  // initialize the serial communication
  Serial.begin(9600);

  // set pins that make sure that ecg leads are properly positioned
  pinMode(ecgMinus, INPUT); // Setup for leads off detection LO -
  pinMode(ecgPlus, INPUT); // Setup for leads off detection LO +

}

void loop() {
  // if 20 milliseconds have passed since last reading
  if (millis() - lastEcg > 20) {
    if(digitalRead(ecgMinus) == 1 || digitalRead(ecgPlus) == 1){
      // send 0 if leads are off
      ecgReading = 0;
    } else {
      // send ECG reading if leads are correctly positioned
      ecgReading = analogRead(ecgOUT);


      // print all sensors values every time that ecg has a new reading
      Serial.print(ecgReading);
      Serial.print(" ");
      Serial.print(windRvReading);
      Serial.print(" ");
      Serial.println(windTmpReading);
    }

    // record time of last reading
    lastEcg = millis();
  }
  if (millis() - lastWind > 200) {
    windRvReading = analogRead(windRV);
    windTmpReading = analogRead(windTMP);
    lastWind = millis();
  }
  if (millis() - lastWind > 200) {
    windRvReading = analogRead(windRV);
    windTmpReading = analogRead(windTMP);
    lastWind = millis();
  }

}
