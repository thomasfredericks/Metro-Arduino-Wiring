/*
 For license and instructions, please read Readme.md.
 */

#ifndef Metro_h
#define Metro_h

#include <inttypes.h>

class Metro
{

public:
  Metro(unsigned long interval_millis);
  Metro(unsigned long interval_millis, uint8_t autoreset);
  void interval(unsigned long interval_millis);
  void delay(unsigned long delay_millis);
  void delayFromNow(unsigned long delay_millis);
  char check();
  void reset();
	
private:
  uint8_t autoreset;
  unsigned long  previous_millis, interval_millis;

};

#endif


