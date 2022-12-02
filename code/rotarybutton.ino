/* ECE411 FALL2022 Team3
   Testing rotary encoder
   -Turning the knob clockwise will print out a statement that says "Rotating clockwise" 
   -Turning the knob counter-clockwise will print out a statement that says "Rotating counter-clockwise"
   -Pressing the button will print out a statement that says "Button pressed"
   
   -Read with 9600 baud rate on the serial monitor.

   Also need to implement a code that will read the rotations once - it currently senses each turn twice.
   Next, we should output the messages on the LCD display, then we can easily put in the timer,
   stopwatch, and game mode.

   For function returning to main menu, we can utilize 'if button pressed > 6 times, go to function'. This
   is equivalent to about 2 seconds. Would probably need to start a count everytime button is pressed
*/

//#include <LiquidCrystal_I2C.h>
//#include <Wire.h>

#define outputA 4 //output A = CLK = pin 4
#define outputB 3 //output B = DW = pin 3

//LiquidCrystal_I2C lcd(0x27,16,2);

//int counter = 0;
int aState;
int aLastState;
int pressButton = 2; //button = SW pin to Arduino pin 2

void setup() {
  //lcd.init(); //initialize LCD
  //lcd.backlight();  //turn on LCD backlight
  pinMode(outputA, INPUT);
  pinMode(outputB, INPUT);
  pinMode(pressButton, INPUT);

  Serial.begin(9600);
  aLastState = digitalRead(outputA); //reads initial state of outputA
}

void loop() {
  int buttonState = digitalRead(pressButton); //read input pin
  aState = digitalRead(outputA); //

  if(buttonState == 0) {
    Serial.print("Button pressed\n");
    delay(200);
  }

  //if the previous/current state of outputA are different, that means a pulse has occured
  if(aState != aLastState) {
    //if outputB state is different to outputA state, that means the encoder is rotating clockwise
    if(digitalRead(outputB) != aState) {
      //counter++;
      Serial.print("Rotating clockwise\n");
    }
    else {
      //counter--;
      Serial.print("Rotating counter-clockwise\n");
    }
    //Serial.print("Position: ");
    //Serial.println(counter);
  }
  aLastState = aState;  //update the previous state of outputA with current state
  //we don't want to add a delay for the rotation of the knobs - it makes us wait a lil before we can turn again
}
