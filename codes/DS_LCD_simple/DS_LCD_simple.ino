#  _________                                         ___ ___          .__       .___                
# /   _____/_____    __ __ _______ _____   ___  __  /   |   \ _____   |  |    __| _/_____   _______ 
# \_____  \ \__  \  |  |  \\_  __ \\__  \  \  \/ / /    ~    \\__  \  |  |   / __ | \__  \  \_  __ \
# /        \ / __ \_|  |  / |  | \/ / __ \_ \   /  \    Y    / / __ \_|  |__/ /_/ |  / __ \_ |  | \/
#/_______  /(____  /|____/  |__|   (____  /  \_/    \___|_  / (____  /|____/\____ | (____  / |__|   
#       \/      \/                     \/                \/       \/            \/      \/         

# Start Of Program---------------------------------------------------------------------------------------------------------


#include <Wire.h>
#include <RealTimeClockDS1307.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

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
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2); 
  pinMode(A3, OUTPUT);
  digitalWrite(A3, HIGH);
  pinMode(A2, OUTPUT);
  digitalWrite(A2, LOW);
}

void loop() {
  RTC.readClock();
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
    lcd.print(hours);
    lcd.print(":");
    lcd.print(minutes);
    lcd.print(":");
    lcd.print(seconds);
    lcd.print(" ");
    lcd.print(tz);
    lcd.setCursor(0, 1);
    lcd.print(dates);
    lcd.print(":");
    lcd.print(months);
    lcd.print(":");
    lcd.print(years);
    delay(250);
    lcd.clear();
    lcd.home();
    lcd.print(hours);
    lcd.print(" ");
    lcd.print(minutes);
    lcd.print(" ");
    lcd.print(seconds);
    lcd.print(" ");
    lcd.print(tz);
    lcd.setCursor(0, 1);
    lcd.print(dates);
    lcd.print(" ");
    lcd.print(months);
    lcd.print(" ");
    lcd.print(years);
    delay(250);
    lcd.clear();
}

