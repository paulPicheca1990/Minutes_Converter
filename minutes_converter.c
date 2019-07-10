/* ###################################################
 * <Author>: Paul Picheca
 * <Data>: 2019-06-21
 * <Purpose>: This is program will take the amount of 
 *            minutes from the user and convert 
 *            the value to { minutes, days, years }
 * 
 * <Remarks>: The program should do 
 * 
 * ################################################### */

#include <stdio.h>
#include "./libs/console_formating.h"
#include "./libs/time_t.h"

void print_table_data( TIME_t time ) {
  char *format = get_column_width_format();
  format[1] = get_direction_character(RIGHT);
  format[strlen(format) - 1] = 'f';
  
  double *current = &time;

  int index;
  for( index = 0; index < time.size; index++ ) {    
    printf( format, *(current + index) );

    if( index < (time.size - 1) )
      printf( " | " );
  }
  
  free(format);
}

/** ################################################################################# 
 *  > Main Program Driver
 *  #################################################################################
 */
int main() {
  print_title();  

  int minutes_entered = 0;  

  printf( "%s", "Please enter the number of minutes: " );
  scanf( "%d", &minutes_entered );

  print_table_header();
  TIME_t time = create_TIME_t(minutes_entered);
  print_table_data(time);

  return 0;
}