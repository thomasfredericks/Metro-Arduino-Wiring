
/*
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */



/*  * * * * * * * * * * * * * * * * * * * * * * * * * * *
 Main code by Thomas O Fredericks (tof@t-o-f.info)
 Contributions by Paul Bouchier and Benjamin.soelberg
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef Metro_h
#define Metro_h

#include <inttypes.h>


class Metro
{

public:
  Metro();
  Metro(unsigned long interval_millis);
  void interval(unsigned long interval_millis);
  void timeout(unsigned long interval_millis);
  void countedExecutions(unsigned long interval_millis, unsigned long number_of_executions);
  void addExecutions(unsigned long number_of_executions);
  void setExecutions(unsigned long number_of_executions);
  uint8_t check();
  void reset();
  void stop();
  void setCatchUp(bool CATCH_UP);
  void setExecuteOnStart(bool EXECUTE_ON_START);

private:
  unsigned long  previous_millis, interval_millis, number_of_executions, previous_number_of_executions;
  bool count_down_enabled;

  bool CATCH_UP = false;
  bool EXECUTE_ON_START = false;

};

#endif
