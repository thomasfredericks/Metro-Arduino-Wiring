/*
For license and instructions, please read Readme.md.
*/


#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "Metro.h"


Metro::Metro(unsigned long interval_millis)
{
	this->autoreset = 0; // Fix by Paul Bouchier
	interval(interval_millis);
	reset();
}

// New creator so I can use either the original check behavior or benjamin.soelberg's
// suggested one (see below). 
// autoreset = 0 is benjamin.soelberg's check behavior
// autoreset != 0 is the original behavior

Metro::Metro(unsigned long interval_millis, uint8_t autoreset)
{   
	this->autoreset = autoreset;
	interval(interval_millis);
	reset();
}

void Metro::interval(unsigned long interval_millis)
{
  this->interval_millis = interval_millis;
}

void Metro::delay(unsigned long delay_millis) {
    this->previous_millis += delay_millis;
}

void Metro::delayFromNow(unsigned long delay_millis) {
    this->previous_millis = millis()+delay_millis;
}

// Benjamin.soelberg's check behavior:
// When a check is true, add the interval to the internal counter.
// This should guarantee a better overall stability.

// Original check behavior:
// When a check is true, add the interval to the current millis() counter.
// This method can add a certain offset over time.

char Metro::check()
{
  unsigned long now_millis = millis();
  if (this->previous_millis<now_millis
      &&(now_millis - this->previous_millis >= this->interval_millis)) {
    // As suggested by benjamin.soelberg@gmail.com, the following line 
    // this->previous_millis = millis();
    // was changed to
    // this->previous_millis += this->interval_millis;
    
    // If the interval is set to 0 we revert to the original behavior
    if (this->interval_millis <= 0 || this->autoreset ) {
    	this->previous_millis = now_millis;
	} else {
		this->previous_millis += this->interval_millis; 
	}
    
    return 1;
  }
  
  
  
  return 0;

}

void Metro::reset() 
{
 
  this->previous_millis = millis();

}


