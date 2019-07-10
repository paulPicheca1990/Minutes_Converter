#ifndef __CONSOLE_FORMATING_H__
#define __CONSOLE_FORMATING_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

extern const int TOTAL_PROGRAM_WIDTH;
extern const int NUMBER_OF_COLUMNS;
extern const char *COLUMNS[];
extern const char *PROGRAM_TITLE;

typedef const enum { 
  LEFT, RIGHT 
} DIRECTION_t;

char *get_text_bar();

char get_direction_character( DIRECTION_t direction );

char *get_direction_string( DIRECTION_t direction );

char *get_preprocess_format_string( DIRECTION_t direction );

char *format_string( const int size,  DIRECTION_t direction );

void print_dividing_bar();

int get_number_of_columns();

int get_fixed_column_width();

char *get_column_width_format();

void print_columns( const char *format, const char *columns[], const int number_of_columns );

void print_title();

void print_table_header();

#endif