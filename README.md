Metro-Arduino-Wiring
====================

Metro library for Arduino or Wiring that facilitates the implementation of recurring timed events.


License
====================

MIT License (MIT)
Copyright (c) 2012 Thomas O Fredericks

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


Version
====================
2.3.2


Latest changes
====================

• Added "this->autoreset = 0; to Metro(unsigned long interval_millis)" as suggested by Paul Bouchier


Installation
====================

• Put the Metro folder in your Arduino "libraries".


Usage
====================

• Metro(unsigned long interval)

Instantiates a Metro object with a set interval in milliseconds with no autoreset

• Metro(unsigned long interval, byte autoreset)

Instantiates a Metro object with a set interval in milliseconds.
If the autoreset is set to true (1), the internal timer will reset, ignoring missed events. If you want to catch up with missed events (because you don't call the check method regularly), set autoreset to false.

• byte check()

Because Metro does not use interrupts, you have to "check" the Metro regularly (at least every millisecond). check() returns true if the interval has lapsed. Returns false if not.

• void interval(unsigned long interval)

Changes the interval in milliseconds.

• void reset()

Restarts/resets the Metro.


Example 1
====================

/*
 This code will blink a LED attached to pin 13 on and off. 
 It will stay on for 0.25 seconds.
 It will stay off for 1 second.
 */
#include <Metro.h> // Include Metro library
#define LED 13 // Define the led's pin

// Create a variable to hold the led's current state
int state = HIGH;

// Instantiate a metro object and set the interval to 250 milliseconds (0.25 seconds).
Metro ledMetro = Metro(250); 

void setup()
{
  pinMode(LED,OUTPUT);
  digitalWrite(LED,state);
}

void loop()
{
  if (ledMetro.check() == 1) { // check if the metro has passed it's interval .
    if (state==HIGH)  { 
      state=LOW;
      ledMetro.interval(250); // if the pin is HIGH, set the interval to 0.25 seconds.
    } 
    else {
      ledMetro.interval(1000); // if the pin is LOW, set the interval to 1 second.
      state=HIGH;
    }
    digitalWrite(LED,state);
  }
}

Example 2
====================

// This example sends a Serial message every 250 milliseconds

#include <Metro.h> // Include the Metro library

Metro serialMetro = Metro(250);  // Instantiate an instance

void setup() {
  Serial.begin(115200); // Start the Serial communication
}

void loop() {

  if (serialMetro.check() == 1) { // check if the metro has passed it's interval .
  // Output all the analog readings seperated by a space character
    for (int i = 0; i < 6; i++ ) {
      Serial.print (analogRead( i) );
      Serial.print(32,BYTE);
    }
    // Terminate message with a linefeed and a carriage return
    Serial.print(13,BYTE);
    Serial.print(10,BYTE);
  }
}