#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "hash.h"
#include "structures.h"

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

Flight blankFlight() {
  Flight f;
  f.month = 0;
  f.day = 0;
  f.weekday = 0;

  f.airline[0] = f.airline[1] = 'X';
  f.org_air[0] = f.org_air[1] = f.org_air[2] = 'X';
  f.dest_air[0] = f.dest_air[1] = f.dest_air[2] = 'X';

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

/*
&(vol->airline)[0], &(vol->airline)[1],
&(vol->org_air)[0], &(vol->org_air)[1], &(vol->org_air)[2],
&(vol->dest_air)[0], &(vol->dest_air)[1], &(vol->dest_air)[2],
*/

int main() {
  Flight f = blankFlight();
  Flight* vol = &f;
  char* line = "1 1 4 MQ DFW BTR 730   383 853  0 1";
  //strcpy(line, "1,1,4,MQ,DFW,BTR,730,,,383,853,,0,1");
  //strcpy(line, "1,1,4,AA,DFW,MSY,1250,84.0,64.0,447,1410,83.0,0,0");
  bool ismissingfields = true;
  int diverted = 0, canceled = 0;
  if (!ismissingfields)
  {
    // If all fields are filled in
    sscanf(line, "%d %d %d %s %s %s %d %f %f %d %d %f %d %d",
              &(vol->month),
              &(vol->day),
              &(vol->weekday),
              &(vol->airline),
              &(vol->org_air),
              &(vol->dest_air),
              &(vol->sched_dep),
              &(vol->dep_delay), // optional
              &(vol->air_time), // optional
              &(vol->dist),
              &(vol->sched_arr),
              &(vol->arr_delay), // optional
              &diverted,
              &canceled
            );
    vol->diverted = diverted == 1 ? true : false;
    vol->canceled = canceled == 1 ? true : false;
    //return 0;
  }
  else
  {
    // If delays and airtime are missing
    sscanf(line, "%d %d %d %s %s %s %d   %d %d  %d %d",
              &(vol->month),
              &(vol->day),
              &(vol->weekday),
              &(vol->airline),
              &(vol->org_air),
              &(vol->dest_air),
              &(vol->sched_dep),
              &(vol->dist),
              &(vol->sched_arr),
              &diverted,
              &canceled
            );
    // Initial values for missing fields is set to 0 here
    vol->dep_delay = 0;
    vol->arr_delay = 0;
    vol->air_time = 0;
    // Converting diverted and canceled to bool
    vol->diverted = diverted == 1 ? true : false;
    vol->canceled = canceled == 1 ? true : false;
    //return 0;
  }
  //return 0;
  //return 0;
  printFlight(f);
  //free(line);
  //free(vol);
}
