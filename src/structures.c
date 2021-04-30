#include "structures.h"

void printIATA(char iata[], int size) {
  for (int i = 0; i<size; i++)
  {
    printf("%c", iata[i]);
  }
}

Flight blankFlight() {
  // Initailizes all fields to 0
  Flight f;
  f.month = 0;
  f.day = 0;
  f.weekday = 0;

  for (int i = 0; i<LEN_IATA_AIRLINE, i++)
  {
    f.airline[i] = '0';
  }
  for (int i = 0; i<LEN_IATA_AIRPORT; i++)
  {
    f.org_air[i] = '0';
    f.dest_air[i] = '0';
  }

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
  printIATA(f.airline, LEN_IATA_AIRLINE);
  printf(",");
  printIATA(f.org_air, LEN_IATA_AIRPORT);
  printf(",");
  printIATA(f.dest_air, LEN_IATA_AIRPORT);
  printf(",");
  printf("%d,", f.sched_dep);
  printf("%f,", f.dep_delay);
  printf("%f,", f.air_time);
  printf("%d,", f.dist);
  printf("%d,", f.sched_arr);
  printf("%f,", f.arr_delay);
  printf("%d,", f.diverted ? 1 : 0);
  printf("%d\n", f.canceled ? 1 : 0);
}
