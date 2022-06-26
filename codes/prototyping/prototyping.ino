#include <Wire.h>
#include <RealTimeClockDS1307.h>
#include "DHT.h"

#define DHTPIN 2     // what pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11 
// #define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
DHT dht(DHTPIN, DHTTYPE);

// LCD
// LCD RS=3, EN=4, DS4=5, DS5=6, DS6=7, DS7=8
#include <LiquidCrystal.h>
LiquidCrystal lcd( 3, 4, 5, 6, 7, 8);
#define Display_Clock_Every_N_Seconds 10 
#define Display_ShortHelp_Every_N_Seconds 60
String tz;
int hours = 0;
int minutes = 0;
int seconds = 0;
int dates = 0;
int months = 0;
int years = 0;
int ap = 0;








const int  buttonPin = A0; // the pin that the pushbutton is attached to
const int  buttonPin1 = A1;
const int ledPin = 11;       // the pin that the LED is attached to
const int ledPin1 = 12;





// Variables will change:
int buttonPushCounter = 1;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

int buttonPushCounter1 = 1;   // counter for the number of button presses
int buttonState1 = 0;         // current state of the button
int lastButtonState1 = 0;     // previous state of the button


void setup() {
   Serial.begin(9600);

  // set up the LCD's number of columns and rows: 
  lcd.begin(16,2);
  dht.begin(); 
  lcd.setCursor(0,0);
  lcd.print("   WELCOME       ");
  lcd.setCursor(0,1);
  lcd.print("      SAURAV! ");
  
  delay(4000);
  lcd.clear();
  
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communication:

   // initialize the button pin as a input:
  pinMode(buttonPin1, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin1, OUTPUT);
  // initialize serial communication:

  
 
}


void loop() {








  

  
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter);
    }
    else {
      // if the current state is LOW then the button
      // wend from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState1 = buttonState1;



// read the pushbutton input pin:
  buttonState1 = digitalRead(buttonPin1);

  // compare the buttonState to its previous state
  if (buttonState1 != lastButtonState1) {
    // if the state has changed, increment the counter
    if (buttonState1 == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
      buttonPushCounter1++;
      Serial.println("on");
      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter1);
    }
    else {
      // if the current state is LOW then the button
      // wend from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState = buttonState;


  // turns on the LED every four button pushes by
  // checking the modulo of the button push counter.
  // the modulo function gives you the remainder of
  // the division of two numbers:
  if (buttonPushCounter % 2 == 0) {
    digitalWrite(ledPin, HIGH);

    int h = dht.readHumidity();
  int t = dht.readTemperature();

    // set the cursor to (0,0):
  lcd.setCursor(0, 0);
  // print from 0 to 9:
  
   lcd.print("# TEMPERATURE  #");
  lcd.setCursor(6, 1);
  lcd.print(t);
   lcd.print((char)223);
   lcd.print("C");
   delay(3000);
   digitalWrite(ledPin, LOW);
      lcd.clear();
      buttonPushCounter++;
   
   
  } else if(buttonPushCounter1 % 2 == 0){digitalWrite(ledPin, LOW);
       digitalWrite(ledPin1, HIGH);
int h = dht.readHumidity();
  int t = dht.readTemperature();
// set the cursor to (0,0):
  lcd.setCursor(0, 0);
  // print from 0 to 9:
  lcd.setCursor(0,0);
  lcd.print("#   HUMIDITY   #");

  lcd.setCursor(6,1);
  lcd.print(h);
  lcd.print("%");

delay(3000);
  digitalWrite(ledPin1, LOW);
      lcd.clear();
      buttonPushCounter1++;
  




  }else{    

  RTC.readClock();
  RTC.is12hour();
    if(ap == 1)
    {
    tz = "PM";
    }
    else
    {
    tz ="AM";
    }
    lcd.home();
    hours = RTC.getHours();
    minutes = RTC.getMinutes();
    seconds = RTC.getSeconds();
    ap = RTC.isPM();
    dates = RTC.getDate();
    months = RTC.getMonth();
    years = RTC.getYear();
    if (hours>=12)
    {
      hours=hours-12;
    }
lcd.print("  ");
    lcd.print(hours);
    lcd.print(":");
    lcd.print(minutes);
    lcd.print(":");
    lcd.print(seconds);
    lcd.print(" ");
    lcd.print(tz);
    lcd.setCursor(1,8);
    lcd.print(" ");
    lcd.print(dates);
    lcd.print(":");
   switch(months)
  {
  case 1: lcd.print("JAN ");break;
    case 2: lcd.print("FEB");break;
    case 3: lcd.print("MA ");break;
    case 4: lcd.print("APR");break;
    case 5: lcd.print("MAY");break;
    case 6: lcd.print("JUN");break;
    case 7: lcd.print("JUL");break;
    case 8: lcd.print("AUG");break;
    case 9: lcd.print("SEP");break;
    case 10: lcd.print("OCT");break;
    case 11: lcd.print("NOV");break;
    case 12: lcd.print("DEC");break;
    default: lcd.print("ERR");break;
  } 
    lcd.print(":");
     lcd.print("20");
    lcd.print(years);
    delay(150);
    lcd.clear();
    lcd.home();
  }
}









