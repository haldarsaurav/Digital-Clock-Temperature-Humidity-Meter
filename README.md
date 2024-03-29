# Digital-Clock-Temperature-Humidity-Meter

<ul>
  <li>Here in this porject I designed and produced a clock that can show the date, month, year, time, temperature, and humidity.</li>
  <li>I used and earned and designed using code written in C/C++ coded in Arduino IDE, using hardware such as ATMEGA328 as the primary IC, RTC DS3231 for clocking, Sensors DHT11 for humidity sensing, LM35 and my tempaerature sensor, and Voltage Regulator 7805.</li>
  <li>For the final build used Eagle CAD Software and Fritzing for PCB design.</li>
  <li>Designed wooden casing/enclosure for final presentation in AutoCAD for a completed end-user product, which I personally used as my desk clock and climate monitor</li>
</ul>  
  
## How the final desk clock looks :) 


<p align="center">
  <img width="500" height="600" src="img/box_enclosure9-min.png">
</p>

![box_enclosuret!](img/box_enclosure10-min.png "box_enclosure")

### Idea for the project

Once, in one of my classes at university, I was doodeling and thought about a desk clock which can show me also the ambient temperature and humiduty, then I started imaging the design and started making addidtions to the idea profressively. 

![box_enclosuret!](img/idea_sketch1-min.png "box_enclosure")

and thought about the interface and other additions I can make to it. 

![box_enclosuret!](flowchart._schematic_block_diagram/LCD_interface_sketch.JPG "box_enclosure")

### Breadboard Prototype! 

So, like with every project, I started out making the project or prototyping it on the breadboard and everythihg seemed to work fine. 

![box_enclosuret!](img/bread_board_build1-min.png "box_enclosure")

![box_enclosuret!](img/bread_board_build2-min.png "box_enclosure")


## You can also see the working here 

>[Video of working prototype](videos/prototype1.AVI "Video of working prototype") 

## Now, the hard part! 

### The Microcontroller

Transferring the breadboard circuit in a more permanent way, first was to make the arduio itself, since I can't sacrifice my only one arduino for this project :) 
Here, I made 2 versions of the arduino. 

![box_enclosuret!](img/arduino_boards-min.png "box_enclosure")

![box_enclosuret!](img/prototype1_arduino-min.png "box_enclosure")

![box_enclosuret!](img/prototype1_arduino_soldering-min.png "box_enclosure")

although the boards were perfect and I flashed the new ATMEGA328 IC using my existing arduiono uno, I ended up not using it, beecause of reasons explaineed later.
### The RTC 

For the RTC, I used DS1307 and made a breakout board for it and it worked perfectly. 

![box_enclosuret!](img/prototype1_RTC-min.png "box_enclosure")

### Final Assembly

After making the IC and RTC, time to make everything from the different modules and interfacing the LCD  

![box_enclosuret!](img/prototype1_module_board-min.png "box_enclosure")
![box_enclosuret!](img/prototype1_module_board_soldering-min.png "box_enclosure")

Power Supply 

![box_enclosuret!](img/prototype1_power_supply-min.png "box_enclosure")

and the final assembly!

![box_enclosuret!](img/prototype_1-min.png "box_enclosure")

## The Enclosure

So, since I wanted this to be my persoanl desk clock, I wanted a nice sleek wooden case for it, I didn't have much tools or resources but, I am glad how it turned out.

![box_enclosuret!](img/box_enclosure2-min.png "box_enclosure")

added some blocks of wood for the back plate to close the box. 
![box_enclosuret!](img/screw_holes-min.png "box_enclosure")


![box_enclosuret!](img/box_enclosure3-min.png "box_enclosure")


Added soem wood filler to hide the imperfections
![box_enclosuret!](img/box_enclosure6-min.png "box_enclosure")

Painted it with wood paint and also added some hole at the top for vents. 
![box_enclosuret!](img/box_enclosure8-min.png "box_enclosure")

# The Problems

Since, I made all the things modular and generally, when there are too many points of connectiuosn there are also more points for failure, sso, i decided to scrap the idea of modularity ane made everything again on a single PCB. 

![box_enclosuret!](img/final_board3-min.png "box_enclosure")

and for RTC i used a premade board with a better IC the DS3132

![box_enclosuret!](img/final_RTC-min.png "box_enclosure")

andf the final board looked much cleaner was really reliable with eveyurhign on the board itself just all the auxillary components needs to be connected via pin connectors. 

![box_enclosuret!](img/final_project_board-min.png "box_enclosure")
![box_enclosuret!](img/final_board_soldering-min.png "box_enclosure")

 the final assembly inside the enclosure :)
 
 ![box_enclosuret!](img/final_assembly-min.png "box_enclosure")
 
 ![box_enclosuret!](img/final_assembly2-min.png "box_enclosure")
 
 Finally :) 
 
 ![box_enclosuret!](img/box_enclosure9-min.png "box_enclosure")





## The final code

    #  _________                                         ___ ___          .__       .___                
    # /   _____/_____    __ __ _______ _____   ___  __  /   |   \ _____   |  |    __| _/_____   _______ 
    # \_____  \ \__  \  |  |  \\_  __ \\__  \  \  \/ / /    ~    \\__  \  |  |   / __ | \__  \  \_  __ \
    # /        \ / __ \_|  |  / |  | \/ / __ \_ \   /  \    Y    / / __ \_|  |__/ /_/ |  / __ \_ |  | \/
    #/_______  /(____  /|____/  |__|   (____  /  \_/    \___|_  / (____  /|____/\____ | (____  / |__|   
    #       \/      \/                     \/                \/       \/            \/      \/         

    # Start Of Program---------------------------------------------------------------------------------------------------------

    //////////////////////////////////////////////////////////////////////////////////
    //              CLOCK + TEMPERATURE + HUMIDITY METER WITH DISPLAY                /
    //                      Code written and designed By:-                           /
    //                      ***** SAURAV HALDAR *****                                /
    //                         haldarsaurav13@gmail.com                              /
    //                                                                               /
    //                                                                               /
    // Credits:- LADYADA (Limor Fried of ADAFRUIT INDUSTRIES for the DHT11 library)  /
    //                                   and                                         /
    //        Mr.Tom Igoe (his State change detection example as a reference)        /
    //                           (for the menu system)                               /
    //////////////////////////////////////////////////////////////////////////////////



                                      /*-----( Header Files )-----*/

    #include <Wire.h>                                       // This library allows you to communicate with I2C devices.
    #include <RealTimeClockDS1307.h>                        // The RTC library (even though it says DS1307, I am using DS3231 it will work fine). 
    #include "DHT.h"                                        // The Library for the Humidity sensor DHT11.
    #include <LiquidCrystal.h>                              // The library for the LCD. 

                                      /*-----( Declare objects )-----*/

    #define DHTPIN 2                                        // Gives a name to a constant value before the program is compiled (const can be used too).
                                                            // DHTPIN 2 indicates the Humidity output is connected to the Pin 2(Digital). 


    #define DHTTYPE DHT11                                   // Whether it is a DHT11 or a DHT22 (refer LADYADA'S library file for this).

    DHT dht(DHTPIN, DHTTYPE);                               // Initialise the DHT11.

    LiquidCrystal lcd( 3, 4, 5, 6, 7, 8);                   // Initialise the LCD. To learn more --> https://www.arduino.cc/en/Reference/LiquidCrystal?from=Tutorial.LCDLibrary


     /*( Objects required for the CLOCK interface.  )*/
    String tz;                                              // String for AM PM.
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    int dates = 0;
    int months = 0;
    int years = 0;
    int ap = 0;                                            // Store 1 or 0 if it is PM or not (refer the RTC library for this). 

     /*( Objects required for the TEMPERATURE interface.  )*/
    float temp;                                            // Object required for the TEMPERATURE interface. 
    int tempPin = 2;                                       // LM35's output connected to Analog 2



     /*( Objects required for the Buttons and LEDs  )*/
    const int  buttonPin = A0;                             // the pin that the pushbutton is attached to
    const int  buttonPin1 = A1;
    const int ledPin = 11;                                 // the pin that the LED is attached to
    const int ledPin1 = 12; 
    const int ledPin2 = 13;

     /*( Objects required for the Virtual Menu system  )*/
    int buttonPushCounter = 1;                             // counter for the number of button presses
    int buttonState = 0;                                   // current state of the button
    int lastButtonState = 0;                               // previous state of the button

    int buttonPushCounter1 = 1;                            // counter for the number of button presses
    int buttonState1 = 0;                                  // current state of the button
    int lastButtonState1 = 0;                              // previous state of the button


                                          /*----( SETUP: RUNS ONCE )----*/

    void setup() 
    {
      Serial.begin(9600);                                  // Sets the data rate in bits per second (baud) for serial data transmission. 
                                                           // For communicating with the computer, use one of these rates.
      lcd.begin(16,2);                                     // initialize the lcd for 16 chars 2 lines, turn on backlight.
      dht.begin(); 
      lcd.setCursor(0,0);                                  // Set the cursor initailly at 0,0( at the top left corner). 

     /*( Print your message here  )*/
      lcd.print("   WELCOME       ");
      lcd.setCursor(0,1);                                  // Set the cursor for the second line( the second 1 after comma sets the cursor at the 2 or lower line).
      lcd.print("      SAURAV! ");

      /*(Leds's which light up when you click for the Temperature and Humidity )*/
      pinMode(buttonPin, INPUT);                           // Initialising the pushbutton for    as INPUT 
      pinMode(ledPin, OUTPUT);                             // Initialising the led for      as OUTPUT                        

      pinMode(ledPin1, OUTPUT);                            // Initialising the led for      as OUTPUT 
      pinMode(buttonPin1, INPUT);                          // Initialising the pushbutton for      as INPUT      

      pinMode(ledPin2, OUTPUT);                            // Initialising the led for      as OUTPUT 

       /*( All the led's will glow when the device is started  )*/
      digitalWrite(ledPin, HIGH);             
      digitalWrite(ledPin1, HIGH);


       /*(Change this number for how much you wanr the lcd to display the starting MESSEGE and all leds to stay ON )*/ 
      delay(4000);                                          // It is in milliseconds

      lcd.clear();                                          // after your set time the display is cleared (the starting message).

       /*(leds will turn OFF after the said (delay) time )*/
      digitalWrite(ledPin, LOW);
      digitalWrite(ledPin1, LOW);



    }/* end setup */


                                                  /*----( LOOP: RUNS CONSTANTLY duh! )----*/
    void loop()
    {


       /*----( Code for your MENU system )----*/
      buttonState = digitalRead(buttonPin);                  // compare the buttonState to its previous state
      if (buttonState != lastButtonState) 
      {                                                    
        if (buttonState == HIGH)                             // if the state has changed, increment the counter
        {
          buttonPushCounter++;                               // if the current state is HIGH then the button
                                                             // went from OFF to ON:
        }
        delay(50);                                           // Delay a little bit to avoid bouncing. For more info--> https://www.arduino.cc/en/Tutorial/Debounce.
      }                                                      // save the current state as the last state,
                                                             //for next time through the loop
      lastButtonState1 = buttonState1;

      buttonState1 = digitalRead(buttonPin1);                // read the pushbutton input pin:

      if (buttonState1 != lastButtonState1)                  // compare the buttonState to its previous state
      {
        if (buttonState1 == HIGH)                            // if the state has changed, increment the counter
        {
                                                             // if the current state is HIGH then the button
                                                             // wen from OFF to ON:
          buttonPushCounter1++;
        }
        else 
        delay(50);                                           // Delay a little bit to avoid bouncing
      }
                                                             // save the current state as the last state,
                                                             //for next time through the loop
      lastButtonState = buttonState;

      // checking the module of the button push counter.
      // the modulo function gives you the remainder of
      // the division of two numbers:

      /*( Code block for the TEMPERATURE interface )*/
      if (buttonPushCounter % 2 == 0) 

      {
        digitalWrite(ledPin, HIGH); 
        temp = analogRead(tempPin);

        temp = temp * 0.48828125;

        lcd.setCursor(0, 0);                                // Set the cursor initailly at 0,0( at the top left corner).

        /*( Printing the TEMPERATURE )*/
        lcd.print("# TEMPERATURE  #");
        lcd.setCursor(4, 1);
        lcd.print(temp);
        lcd.print((char)223);                               // for the degree sign( degree C).
        lcd.print("C");

        /*(Change this number for how much you want the lcd to display the TEMPERATURE )*/ 
        delay(5000);                                        // it is in milliseconds
        digitalWrite(ledPin, LOW);                          // light OFF the led.
        lcd.clear();                                        // Clears up the led.
        buttonPushCounter++;                                // this is the trick to make the lcd to display the CLOCK interface againg (it is basically exiting this loop).
     } 
      else 

      /*( Code block for the HUMIDITY interface )*/
      if(buttonPushCounter1 % 2 == 0)
      {

        digitalWrite(ledPin1, HIGH);                       // light up the led.
        int h = dht.readHumidity();                        // getting the reading from the DHT11.
        lcd.setCursor(0,0);                                // Set the cursor initailly at 0,0( at the top left corner).

        /*( Printing the HUMIDITY )*/
        lcd.print("#   HUMIDITY   #");
        lcd.setCursor(6,1);
        lcd.print(h);
        lcd.print("%");


        /*(Change this number for how much you want the lcd to display the HUMIDITY )*/ 
        delay(5000);                                       // it is in milliseconds.
        digitalWrite(ledPin1, LOW);                        // Light OFF the led.
        lcd.clear();                                       // Clears the LCD.
        buttonPushCounter1++;                              // this is the trick to make the lcd to display the CLOCK interface againg (it is basically exiting this loop).

      }

      /*( Code block for the CLOCK interface )*/
      else
      {    
        RTC.readClock();                                   // After the clock is turned on using the Start command. 
                                                           // You need to read the data from the RTC module. 
                                                           // This is done by the readClock function. This function is essential before the latter commands can be used.
        RTC.is12hour();                                    // Toggles between the 12hour mode and 24hour mode.

       /*( to check whether it is AM or PM )*/ 
        if(ap == 1)
        {
        tz = "PM";
        }
        else
        {
        tz ="AM";
        }
        lcd.home();                                       // Positions the cursor in the upper-left of the LCD

         /*( Storing the time into the designated variables )*/ 
        hours = RTC.getHours();
        minutes = RTC.getMinutes();
        seconds = RTC.getSeconds();
        ap = RTC.isPM();
        dates = RTC.getDate();
        months = RTC.getMonth();
        years = RTC.getYear();

        /*( This is the trick I used to make the clock switch between the 12 and 24 hour mode(i cannot get the RTC.is12hour work :-(.   ) )*/ 
        if (hours>12)
        {
          hours=hours-12;
        }



        /*( Printing the CLOCK )*/
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

       /*( This is the Block I made to display the month (i don't know how to print day tell me if anyone knows that :-).  ) )*/ 
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
        lcd.print("20");                                            // To print the year 20(constant till (2099)-----15(the variable years).
        lcd.print(years);                                                  
        delay(150);                                                 // Refresh
        lcd.clear();
        lcd.home();
      }
    }                                                                         

    //////////////////////////////////////////////////////////////////////////////////
    //                      Code written and designed By:-                           /
    //                      ***** SAURAV HALDAR *****                                /
    //                         haldarsaurav13@gmail.com                              /
    //                                                                               /
    //////////////////////////////////////////////////////////////////////////////////








