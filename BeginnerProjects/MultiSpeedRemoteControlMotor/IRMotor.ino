#include <IRremote.h>

const int IR_RECEIVE_PIN = 11;  // Pin connected to IR sensor's Y (signal)
const int MOTOR_PIN = 9;
boolean motorOn = false;
int speed = 0;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start receiver on pin 11
  pinMode(MOTOR_PIN, OUTPUT);
}

void loop() {
  
  if (IrReceiver.decode()) {
    // Print raw HEX value of the button pressed
    Serial.print("Received command: 0x");
    Serial.println(IrReceiver.decodedIRData.command, HEX);
    
    if(IrReceiver.decodedIRData.command == 0x45) {
      motorOn = !motorOn;
      Serial.println("Motor Command DETECTED!");
    }

    if(IrReceiver.decodedIRData.command!=0x0){delay(250);}

    if(IrReceiver.decodedIRData.command==0xC) {speed = 77;}
    if(IrReceiver.decodedIRData.command==0x18) {speed=125;}
    if(IrReceiver.decodedIRData.command==0x5E) {speed=250;}
    if(IrReceiver.decodedIRData.command==0x9) {speed+=10;delay(150);}
    if(IrReceiver.decodedIRData.command==0x7) {speed-=10;delay(150);}
    if(speed>255) {speed=255;}
    IrReceiver.resume();  // Ready to receive the next signal
    

    
  }

  if(motorOn) {
    analogWrite(MOTOR_PIN, speed);
    delay(300);
  } else {
    analogWrite(MOTOR_PIN, 0);
    delay(300);
  }
  
}