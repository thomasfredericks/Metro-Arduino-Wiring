

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "Metro.h"

Metro::Metro()
{

	number_of_executions = 0;

}

Metro::Metro(unsigned long interval_millis)
{

	number_of_executions = 1;
	this->interval_millis = interval_millis;

}

void Metro::interval(unsigned long interval_millis)
{

	previous_millis = millis();
  this->interval_millis = interval_millis;
	this->number_of_executions = 1;
	count_down_enabled = false;

}

void Metro::timeout(unsigned long interval_millis)
{

	previous_millis = millis();
	this->interval_millis = interval_millis;
	this->number_of_executions = 1;
	count_down_enabled = true;

}

void Metro::countedExecutions(unsigned long interval_millis, unsigned long number_of_executions)
{

	previous_millis = millis();
	this->interval_millis = interval_millis;
	this->number_of_executions = number_of_executions;
	count_down_enabled = true;

}

void Metro::addExecutions(unsigned long number_of_executions)
{

	this->number_of_executions += number_of_executions;
	count_down_enabled = true;

}

void Metro::setExecutions(unsigned long number_of_executions)
{

	this->number_of_executions = number_of_executions;
	count_down_enabled = true;

}

uint8_t Metro::check()
{

	unsigned long now = millis();

	if(EXECUTE_ON_START && previous_millis == 0){
		previous_millis = millis();
		Serial.println("innerTrig!!");
		return 1;
	}

  if ( interval_millis == 0 && number_of_executions > 0) {
		if( count_down_enabled ) {
			number_of_executions--;
		}
    previous_millis = now;
		return 1;
  }

  if ( (now - previous_millis) >= interval_millis && number_of_executions > 0) {
		if( !CATCH_UP ) {
			previous_millis = now;
		}
		else{
			previous_millis += interval_millis;
		}

		if( count_down_enabled ) {
			number_of_executions--;
		}
    return 1;
  }

  return 0;

}

void Metro::reset()
{

	if(EXECUTE_ON_START){
		this->previous_millis = 0;
	}
	else{
		this->previous_millis = millis();
	}

	if(count_down_enabled){
		number_of_executions = previous_number_of_executions;
	}else{
		number_of_executions = 1;
	}

}

void Metro::stop()
{

	previous_number_of_executions = number_of_executions;
	number_of_executions = 0;

}

void Metro::setCatchUp(bool CATCH_UP)
{

	this->CATCH_UP = CATCH_UP;

}

void Metro::setExecuteOnStart(bool EXECUTE_ON_START)
{

	this->EXECUTE_ON_START = EXECUTE_ON_START;

}
