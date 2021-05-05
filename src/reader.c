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

int retrieveNextLine(FILE* fp, char** line, int max_lenght_line) {
  if (fgets(*line, max_lenght_line, fp) == NULL)
    // If the end of file has been reached, return 1
    return 1;
  formatStr(line);
  return 0;
}

int readOneFlight(FILE* fp, Flight* vol) {
  /*
    Reads the next line of fp and puts the content in vol
    returns :
      - 0 if everything went well
      - 1 if end of file is reached
      - -1 if something is wrong with the data
  */
  // Retrieve the next line
  // In the file in a string in order to be able to use it multiple times
  char* line;
  if (retrieveNextLine(fp, &line, MAX_LINE_LENGTH_FLIGHTS) == 1)
    return 1;

  // Placeholders for diverted and canceled fields,
  // will be converted to bool later
  int diverted = 0, canceled = 0;
  int nargs = sscanf(line, MASK_FLIGHTS,
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
  // If all fields were filled in
  if (nargs == NARGS_FLIGHTS)
  {
    // Converting diverted and canceled to bool
    vol->diverted = diverted == 1 ? true : false;
    vol->canceled = canceled == 1 ? true : false;
    return 0;
  }
  // If not all fields were filled but it was because the flight was canceled
  else if (nargs == NARGS_FLIGHTS_MIN)
  {
    // If delays and airtime are missing
    sscanf(line, MASK_FLIGHTS_MISSING,
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

int readOneAirline(FILE* fp, Airline* airline) {
  /*
    Reads the next line of fp and puts the content in airline
    returns :
      - 0 if everything went well
      - 1 if end of file is reached
      - -1 if something is wrong with the data
  */
  // Retrieve the next line
  // In the file in a string in order to be able to use it multiple times
  char* line;
  if (retrieveNextLine(fp, &line, MAX_LINE_LENGTH_AIRLINES) == 1)
    return 1;

  int nargs = sscanf(line, MASK_AIRLINES,
                        &(airline.IATA_code),
                        &(airline.name)
                          );
  if (nargs == NARGS_AIRLINES)
    return 0;
  else
    return -1;
}

int readOneAirport(FILE* fp, Airport* airport) {
  /*
    Reads the next line of fp and puts the content in airport
    returns :
      - 0 if everything went well
      - 1 if end of file is reached
      - -1 if something is wrong with the data
  */
  // Retrieve the next line
  // In the file in a string in order to be able to use it multiple times
  char* line;
  if (retrieveNextLine(fp, &line, MAX_LINE_LENGTH_AIRPORTS) == 1)
    return 1;

  int nargs = sscanf(line, MASK_AIRPORTS,
                        &(airport.IATA_code),
                        &(airport.name),
                        &(airport.city),
                        &(airport.state),
                        &(airport.coutry),
                        &(airport.latitude),
                        &(airport.longitude)
                          );
  if (nargs == NARGS_AIRPORTS || nargs == NARGS_AIRPORTS_MIN)
    return 0;
  else
    return -1;
}
