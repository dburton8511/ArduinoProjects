int soilMoisture;
const int sensorPowerPin = 3;
const int motorTransistorPin = 8;
const int ledPinG = 10;
const int ledPinY = 11;
const int ledPinR = 12;

int delayTime=5000;
void setup() {
  Serial.begin(9600);
  pinMode(sensorPowerPin, OUTPUT);
  pinMode(motorTransistorPin, OUTPUT);
  pinMode(ledPinG, OUTPUT);
  pinMode(ledPinY, OUTPUT);
  pinMode(ledPinR, OUTPUT);
}

void loop() {
  digitalWrite(sensorPowerPin, HIGH);
  delay(10);
  soilMoisture = analogRead(A0);
  digitalWrite(sensorPowerPin, LOW);

  Serial.println(soilMoisture);
  if(soilMoisture<500&&soilMoisture!=0) {
    digitalWrite(motorTransistorPin, HIGH);
    delay(10000);
    digitalWrite(motorTransistorPin, LOW);
    Serial.print("Motor is On. Moisture: ");
    digitalWrite(ledPinY, HIGH);
  }else digitalWrite(ledPinY, LOW);

  if(soilMoisture==0) {
    digitalWrite(ledPinR, HIGH);
  } else digitalWrite(ledPinR, LOW);

  

  if(soilMoisture>500) {
    digitalWrite(ledPinG, HIGH);
  }else digitalWrite(ledPinG, LOW);

  delay(delayTime);

}
