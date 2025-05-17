#include "DHT.h" //IMPORTING the library for the temperature and humidity sensor
#include <LiquidCrystal.h> //IMPORTING the library for the screen

//declaring starting values
#define DHTPIN 13  
#define DHTTYPE DHT11
boolean isCelcius = true;//The LCD Will default to showing celcius
const int buttonPin = 8;

//Creating the LiquidCrystal and DHT Objects
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
DHT dht(DHTPIN, DHTTYPE);

 void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  lcd.begin(16, 2); //Sets the size of the lcd display
  dht.begin(); //Turning the dht sensor on
  pinMode(buttonPin, INPUT); // Setting the button to be an input
}

void loop() {
  // put your main code here, to run repeatedly:

  //Reads and sets all of the humidity and temperature values
  float humidity= dht.readHumidity();
  delay(100);
  float celcius = dht.readTemperature();
  delay(100);
  float farenheit = dht.readTemperature(true);
  

  //Sets up the button to flip between showing the temperature in celcius or farenheit
  if(digitalRead(buttonPin)==LOW) {
    isCelcius = !isCelcius;
    delay(250);
  }


  lcd.clear();//Makes the lcd empty
  lcd.setCursor(0, 0); //Starts at the first character
  lcd.print("Humidity: " + String(int(humidity))+"%"); //Prints out the humidity
  lcd.setCursor(0, 1); //Move to the first character of the second line
  lcd.print("Temp: ");

  if(isCelcius){
    lcd.print(String(celcius) + "C");
  } else {
    lcd.print(String(farenheit) + "F");
  }
  delay(1000);
}
