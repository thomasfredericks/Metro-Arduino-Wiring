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

# Metro(unsigned long interval)

Instantiates a Metro object with a set interval in milliseconds with no autoreset

# Metro(unsigned long interval, byte autoreset)

Instantiates a Metro object with a set interval in milliseconds.
If the autoreset is set to true (1), the internal timer will reset, ignoring missed events. If you want to catch up with missed events (because you don't call the check method regularly), set autoreset to false.

# byte check()

Because Metro does not use interrupts, you have to "check" the Metro regularly (at least every millisecond). check() returns true if the interval has lapsed. Returns false if not.

# void interval(unsigned long interval)

Changes the interval in milliseconds.

# void reset()

Restarts/resets the Metro.

# void delay(long millis)

delays the triggering of the next successful check() for the specified amount of milliseconds. 

# void delayFromNow(long millis)

delays the triggering of the next successful check() for the specified amount of milliseconds after now.
After millis() + the specified milliseconds the Metro goes back to normal operation 
