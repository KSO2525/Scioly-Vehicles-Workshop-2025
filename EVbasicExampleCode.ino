/* 
Kai Song 
August, 2025
Science Olympiad SoCal Build Workshop, Summer 2025
With thanks to: SoCal Science Olympiad, lab64
Creative Commons License 

""We are tied to the ocean. And when we go back to the ocean - whether it is to sail or to watch it - we are going back from whence we came" - JFK
*/

//-----------------------------------------------------------------------------

/*
WIRING:

- A diagram of which pins from the ESP32 go to which ports is attached to the email. Remember, VSS, GND are labeled on the motor driver board.
- Use the stripped wires (stripped on both sides) to extend the motor cables and screw those into either pair of screw terminals.
- Use the stripped on one side wires to connect VSS and GND from the ESP32 to the motor driver board.
- Use the unstripped wires to connect in1 & in2 pins on ESP32 to the two pins closest the screw terminals the motor are 
  plugged in to. (either in1 & in2    or    in3 & in4)
*/

int in1 = 12;
int in2 = 13;

void setup() {
  /*The L298N motor driver uses two pins to control what direction the motor spins in. These will be "in1" & "in2"
  They are integers because they represent the pin number on the ESP32 microcontroller*/
  
  //we use the pinMode function to set both in1 and in2 as output pins. Otherwise, the ESP32 doesn't know if they're out/in-put
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  /*
  The following is the table of Low/High combos for motor direction:
   ______________________________________
  |  in1  |  in2   |   Motor Direction   |
  |______________________________________|          
  |  Low  |  Low   |        OFF          |
  |______________________________________|
  |  High |  Low   |       Forward       |
  |______________________________________|
  |  Low  |  High  |      Backward       |
  |______________________________________|
  */

  //We want to start with the motor OFF
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void loop() {
  //We set a delay from when we power the cart on to when it starts to move. Do at least 10,000 milliseconds.
  delay(10000); //TODO: Change start delay according to your wants. Units: milliseconds

  //Set the motor to run!!!
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  //We can again use a simple delay to set how long we want the motors to run for (longer run time => more distance traveled)
  delay(10000);//TODO: Change the runtime. Units: milliseconds
  
  //End with motors off (at target point)
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

/* When you're done editing the code, unplug the power pin from your ESP32 (top pin nearest the USB port). Connect the USB cable and select "ESP32 Dev Module" as the board.
Select the most recently detected COM port. Then click "Upload"s
Unplug USB cable once its done. Then, plug back in the power cable when ready to run!
*/
