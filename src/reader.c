#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"

void formatStr(char** string) {
  /*
  Replaces all ',' in string with whitespaces
  to allow formating using %s in sscanf
  */
  while (*string++ != NULL)
  {
    if (**string == ',')
      **string = ' ';
  }
}

int readOneFlight(FILE* fp, Flight* vol) {
  /*
    Reads the next line of fp and puts the content in vol
    returns :
      - 0 if everything went well
      - 1 if end of file is reached
      - -1 if something is wrong with the data
  */
  // Retrieve the next line in the file
  char* line;
  int max_lenght_line = MAX_LINE_LENGTH_FLIGHTS;
  if (fgets(line, max_lenght_line, fp) == NULL)
    // If the end of file has been reached, return 1
    return 1;
  formatStr(&line);
  // Placeholders for diverted and canceled fields,
  // will be converted to bool later
  int diverted = 0, canceled = 0;

  // If all fields are filled in
  int nargs = sscanf(line, "%d %d %d %s %s %s %d %f %f %d %d %f %d %d",
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
  // Converting diverted and canceled to bool
  vol->diverted = diverted == 1 ? true : false;
  vol->canceled = canceled == 1 ? true : false;
  // If all fields were filled in
  if (nargs == NARGS_FLIGHTS)
    return 0;
  else if (nargs >= NARGS_FLIGHTS_MIN)     // If not all fields were filled but it was because the flight was canceled
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
    // Converting diverted and canceled to bool
    vol->diverted = diverted == 1 ? true : false;
    vol->canceled = canceled == 1 ? true : false;
    return 0;
  }
  else // If not enough fields were filled in
    return -1;
}
