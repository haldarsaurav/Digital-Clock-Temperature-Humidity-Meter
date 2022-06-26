# Digital-Clock-Temperature-Humidity-Meter

<ul>
  <li>Here in this porject I designed and produced a clock that can show the date, month, year, time, temperature, and humidity.</li>
  <li>I used and earned and designed using code written in C/C++ coded in Arduino IDE, using hardware such as ATMEGA328 as the primary IC, RTC DS3231 for clocking, Sensors DHT11 for humidity sensing, LM35 and my tempaerature sensor, and Voltage Regulator 7805.</li>
  <li>For the final build used Eagle CAD Software and Fritzing for PCB design.</li>
  <li>Designed wooden casing/enclosure for final presentation in AutoCAD for a completed end-user product, which I personally used as my desk clock and climate monitor</li>
</ul>  
  
## How the final desk clock looks :) 

![box_enclosuret!](img/box_enclosure9-min.png "box_enclosure")
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
---

you can also see the working here [Video of working prototype](videos/prototype1.AVI "Video of working prototype")

## Now, the hard part! 
### The Microcontroller
Transferring the breadboard circuit in a more permanent way, first was to make the arduio itself, since I can't sacrifice my only one arduino for this project :) 
Here, I made 2 versions of the arduino. 
![box_enclosuret!](img/arduino_boards-min.png "box_enclosure")
![box_enclosuret!](img/prototype1_arduino-min.png"box_enclosure")
![box_enclosuret!](img/prototype1_arduino_soldering-min.png")
although the boards were perfect and I flashed the new ATMEGA328 IC using my existing arduiono uno, I ended up not using it, beecause of reasons explaineed later.
### The RTC 
For the RTC, I used DS1307 and made a breakout board for it and it worked perfectly. 
![box_enclosuret!](img/prototype1_RTC-min.png "box_enclosure")

### Final Assembly 
After making the IC and RTC, time to make everything from the different modules and interfacing the LCD  
![box_enclosuret!](img/prototype1_RTC-min.png "box_enclosure")
![box_enclosuret!](img/prototype1_RTC-min.png "box_enclosure")






