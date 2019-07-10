#ifndef __TIME_T_H__
#define __TIME_T_H__

/** ###################################################
 *  > Constants
 *  ###################################################
 */
// Constants <Measurement>_IN_YEAR
static const int MONTHS_IN_YEAR = 12;
static const int DAYS_IN_YEAR = 365;
static const int HOURS_IN_YEAR = 24 * 365;
static const int MINUTES_IN_YEAR = 60 * 24 * 365;
static const int SECONDS_IN_YEAR = 60 * 60 * 24 * 365;

// Constants <Measurement>_IN_MONTH
static const double DAYS_IN_MONTH = 30.4167;
static const double HOURS_IN_MONTH = 730.001;
static const int MINUTES_IN_MONTH = 43800;
static const double SECONDS_IN_MONTH = 2628000;

// Constants <Measurement>_IN_DAY
static const int HOURS_IN_DAY = 24;
static const int MINUTES_IN_DAY = 60 * 24;
static const int SECONDS_IN_DAY = 60 * 60 * 24;

// Constants <Measurement>_IN_HOUR
static const int MINUTES_IN_HOUR = 60;
static const int SECONDS_IN_HOUR = 60 * 60;

// Constants <Measurement>_IN_MINUTE
static const int SECONDS_IN_MINUTE = 60;

/** ###################################################
 *  > Structures
 *  ###################################################
 */
typedef struct _TIME_t {
  double years;
  double months;
  double days;
  double hours;
  double minutes;
  double seconds;
  int size;
} TIME_t;

/** ###################################################
 *  > Methods
 *  ###################################################
 */
TIME_t create_TIME_t( int minutes );

#endif