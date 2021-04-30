#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#include"structures.h"

int readFlight(FILE* fp, Flight* vol) {
  /*
    Reads the next line of fp,
    returns 0 if everything went well, 1 otherwise
  */

  int diverted = 0, canceled = 0;
  fscanf(fp, "%d,%d,%d,%c%c,%c%c%c,%c%c%c,%d,%f,%f,%d,%d,%f,%d,%d",
              &(vol->month),
              &(vol->day),
              &(vol->weekday),
              &(vol->airline)[0], &(vol->airline)[1],
              &(vol->org_air)[0], &(vol->org_air)[1], &(vol->org_air)[2],
              &(vol->dest_air)[0], &(vol->dest_air)[1], &(vol->dest_air)[2],
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
  return 0;
}
