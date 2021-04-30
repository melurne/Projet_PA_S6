#include "structures.h"

Flight blankFlight() {
  // Initailizes all fields to 0
  Flight f;
  f.month = 0;
  f.day = 0;
  f.weekday = 0;

  f.airline[0] = f.airline[1] = '0';
  f.org_air[0] = f.org_air[1] = f.org_air[2] = '0';
  f.dest_air[0] = f.dest_air[1] = f.dest_air[2] = '0';

  f.sched_dep = 0000;
  f.dep_delay = 0.;

  f.air_time = 0.;
  f.dist = 0;

  f.sched_arr = 0000;
  f.arr_delay = 0.;

  f.diverted = false;
  f.canceled = false;

  return f;
}

void printFlight(Flight f) {
  printf("%d,", f.month);
  printf("%d,", f.day);
  printf("%d,", f.weekday);
  printf("%c%c,", f.airline[0], f.airline[1]);
  printf("%c%c%c,", f.org_air[0], f.org_air[1], f.org_air[2]);
  printf("%c%c%c,", f.dest_air[0], f.dest_air[1], f.dest_air[2]);
  printf("%d,", f.sched_dep);
  printf("%f,", f.dep_delay);
  printf("%f,", f.air_time);
  printf("%d,", f.dist);
  printf("%d,", f.sched_arr);
  printf("%f,", f.arr_delay);
  printf("%d,", f.diverted ? 1 : 0);
  printf("%d\n", f.canceled ? 1 : 0);
}
