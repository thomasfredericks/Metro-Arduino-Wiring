

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "Metro.h"

Metro::Metro()
{
	
	this->interval_millis = 1000;
	
}


Metro::Metro(unsigned long interval_millis)
{
	
	this->interval_millis = interval_millis;
	
}


void Metro::interval(unsigned long interval_millis)
{
  this->interval_millis = interval_millis;
}

uint8_t Metro::check()
{

  unsigned long now = millis();
  
  if ( interval_millis == 0 ){
    previous_millis = now;
	return 1;
  }
 
  if ( (now - previous_millis) >= interval_millis) {
	#ifdef NOCATCH-UP
	previous_millis = now ; 
	#else
	previous_millis += interval_millis ; 
	 #endif
    return 1;
  }
  
  return 0;

}

void Metro::reset() 
{
 
  this->previous_millis = millis();

}


