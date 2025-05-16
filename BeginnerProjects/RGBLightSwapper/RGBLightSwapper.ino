//thank you to DB Tech for the build guide & code! this is my first project so I'm just doing this to learn
//I will add a note to any code here that is original
//If this is posted to my github, just note that I am posting this to document my learning process on arduino

const int buttonPin = 4;  //tutorial said that it should be equal to 3 because it starts at zero but it didn't work, so I changed it to four to accurately be what was written on the pcb
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
const int togglePin = 2; //custom, this is the button that will turn on the changing colour function
int counter = 0;
int lastToggle = 0;
bool isToggled = false;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  int buttonState; int toggleState;
  buttonState = digitalRead(buttonPin);
  toggleState = digitalRead(togglePin); //reads state of toggle pin
  if (buttonState == LOW) {
    counter++;
    delay(250);  

  }

  else if (counter == 0) {
    //Off
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  } else if (counter == 1) {
    //Red
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  } else if (counter == 2) {
    //Green
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
  } else if (counter == 3) {
    //Blue
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  } else if (counter == 4) {
    //Purple
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  } else if (counter == 5) {  //added this part additionally to make the rgb light a pleasant shade of teal
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
  } else if (counter == 6) {  //added this part additionally to make the rgb light turn white
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
  } else {
    counter = 0;
  }

  if(toggleState==LOW) {//checks if the toggle button is clicked
    isToggled=!isToggled; //changes the state of whether or not it is toggled
    delay(250);
  }
  if(isToggled) {
    if(millis()-lastToggle>500) {//delay for 500ms whilst allowing the rest of the code to run
      counter++;
      if(counter>=7){
        counter = 1; //just skips over the part of the phase where the light is off
      }
      lastToggle=millis();
    }

  }
}
