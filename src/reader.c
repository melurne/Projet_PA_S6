#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#include "structures.h"

int readFlight(FILE* fp, Flight* vol) {
  /*
    Reads the next line of fp and puts the content in vol
    returns :
      - 0 if everything went well
      - 1 if end of file is reached
  */
  // Retrieve the next line in the file
  char* line;
  int max_lenght_line = MAX_LINE_LENGTH_FLIGHTS;
  if (fgets(line, max_lenght_line, fp) == NULL)
    // If the end of file has been reached, return 1
    return 1;

  // Check to see if any field is empty (ie there are two ',' next to each other)
  bool ismissingfields = false;
  int i = 0;
  while (line[i+1] != NULL && !ismissingfields)
  {
    if (line[i] == ',' && line[i+1] == ',')
      ismissingfields = true;
    i++;
  }

  // Placeholders for diverted ans canceled fields,
  // will be converted to bool later
  int diverted = 0, canceled = 0;
  if (!ismissingfields)
  {
    // If all fields are filled in
    fscanf(line, "%d,%d,%d,%s,%s,%s,%d,%f,%f,%d,%d,%f,%d,%d",
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
    return 0;
  }
  else
  {
    // If delays and airtime are missing
    fscanf(line, "%d,%d,%d,%s,%s,%s,%d,,,%d,%d,,%d,%d",
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
    return 0;
  }
}
