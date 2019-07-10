#include "../libs/console_formating.h"

const int TOTAL_PROGRAM_WIDTH = 100;
const char *PROGRAM_TITLE = "Minutes Conversions";
const char *COLUMNS[] = {"Years", "Months", "Days", "Hours", "Minutes", "Seconds"};
const int NUMBER_OF_COLUMNS = sizeof(COLUMNS) / sizeof(COLUMNS[0]);

char *get_text_bar() {
  // Allocate a large string for repeating character {i.e. 400 length + 1 null terminator}
  int bar_size = 400;
  char *bar = (char *)malloc( sizeof(char) * (bar_size + 1) ); 
  
  // Place a new character within the newly allocated array
  int index = 0;
  for( index = 0; index < bar_size; index++ ) {
    bar[index] = '=';    
  }  
  bar[index++] = '\0';

  return bar;
}

char get_direction_character( DIRECTION_t direction ) {
  char character;
  switch( direction ){
    case LEFT:
      character = '-';
      break;

    case RIGHT:
      character = '+';
      break;

    default: // Default is left
      character = '-';
      break;
  }
  return character;
}

char *get_direction_string( DIRECTION_t direction ) {
  char *direction_string = (char *)malloc(2);
  direction_string[0] = get_direction_character(direction);  
  direction_string[1] = '\0';
  return direction_string;
}

char *get_preprocess_format_string( DIRECTION_t direction ){
  char *escaped_percent = "%%";
  char *padded_string = "%ds"; 
  char *direction_string = get_direction_string(direction);  

  char *preprocess_format = (char *)malloc( strlen(escaped_percent) + 1 + strlen(padded_string) + 1 );
  strcpy(preprocess_format, escaped_percent);
  strcat(preprocess_format, direction_string);
  strcat(preprocess_format, padded_string);

  free(direction_string);

  return preprocess_format;
}

char *format_string( const int size,  DIRECTION_t direction ) {
  // Allocate a preprocess format string for sprintf    
  char *preprocess_format = get_preprocess_format_string(direction); 

  // Calculate the number of digits required for string padding value
  int number_of_digits = (int) ( log10(size) + 1 );

  // THERE ARE (2) characters removed {% and "%d" -> becomes a value} by sprintf &
  // (1) '\0' character appended to the end
  int format_string_size = ( strlen( preprocess_format ) - 2) + number_of_digits + 1; 
  
  char *format = (char *)malloc( sizeof( format_string_size ) ); 
  sprintf(format, preprocess_format, size );  

  //printf( "\npreprocess: %s format: %s size: %d\n", preprocess_format, format, size );
  free( preprocess_format );

  return format;
}

void print_dividing_bar() {
  // Gather sizing information
  char *bar = get_text_bar();
  const int total_width = TOTAL_PROGRAM_WIDTH;

  // Display
  printf( "%.*s\n", total_width, bar );

  // Free Used Memory
  free(bar);
}

int get_number_of_columns() {
  return (int)( sizeof(COLUMNS) / sizeof( COLUMNS[0] ) );
}

int get_fixed_column_width() {
  return (int)( ( TOTAL_PROGRAM_WIDTH / get_number_of_columns() ) - 2 );
}

char *get_column_width_format() {  
  // Define Column direction
  const DIRECTION_t column_direction = LEFT;

  // Format  
  char *format = format_string( get_fixed_column_width(), column_direction );

  return format;
}

void print_columns( const char *format, const char *columns[], const int number_of_columns ) {
  int index;  
  for( index = 0; index < number_of_columns; index++ ) {
    printf( format, columns[index] );
    if( index != (number_of_columns - 1) && number_of_columns > 1 )
      printf( " | " );
  }
  printf( "\n" );
}

void print_title() {    
  printf( "\n" );
  print_dividing_bar();
  printf( "%s\n", PROGRAM_TITLE );    
  print_dividing_bar();
  printf("\n");
}

void print_table_header() {
  // Sizing and Alignment  
  char *format = get_column_width_format();  

  print_dividing_bar();
  print_columns( format, COLUMNS, get_number_of_columns() );
  print_dividing_bar();
  
  free(format);
}