#include "../libs/time_t.h"

TIME_t create_TIME_t( int minutes ) {
  return (TIME_t){ 
    .years = (double)minutes / MINUTES_IN_YEAR,
    .months = (double)minutes / MINUTES_IN_MONTH,
    .days = (double)minutes / MINUTES_IN_DAY,
    .hours = (double)minutes / MINUTES_IN_HOUR,
    .minutes = (double)minutes,
    .seconds = (double)minutes * SECONDS_IN_MINUTE,
    .size = (int)6
  };  
}