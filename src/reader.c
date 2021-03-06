#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"

void formatStr(char* string) {
  /*
    Replaces the \n character with \0 to properly end the string
  */
  char* current_pos;
  if ((current_pos = strchr(string, '\n')) != NULL)
    *current_pos = 0;
}

int retrieveNextLine(FILE* fp, char** line, size_t max_lenght_line) {
  if (getline(line, &max_lenght_line, fp) == -1)
    // If the end of file has been reached, return 1
    return 1;

  formatStr(*line);
  return 0;
}

void getNextArg(char** curr, char** next, char** target, char seperator) {
  /*
    Fetches the next token in the line
    Puts the result in target
  */
  if (*next == NULL)
    return;
  strncpy(*target, *curr, (*next) - (*curr));
  // Properly finishes the string
  (*target)[(*next) - (*curr)] = 0;
  // Update curr and next to point to the next token in the string
  *curr = *next + 1;
  *next = strchr(*curr, seperator);
}

int readOneAirline(FILE* fp, Airline* airline) {
  /*
    Reads the next line of fp and puts the content in airline
    returns :
      - 0 if everything went well
      - 1 if end of file is reached
      - -1 if something is wrong with the data
  */
  // Retrieve the next line in a string
  char* line = malloc(sizeof(char) * MAX_LINE_LENGTH_AIRLINES);
  if (retrieveNextLine(fp, &line, MAX_LINE_LENGTH_AIRLINES) == 1)
    return 1;

  char* next;
  char* curr = line;
  next = strchr(curr, ',');
  if (next == NULL) {
    free(line);
    return -1;
  }

  getNextArg(&curr, &next, &(airline->IATA_code), ',');

  next = strchr(curr, '\0');
  strcpy(airline->name, curr);
  airline->name[next - curr + 1] = 0;

  free(line);
  return 0;
}

int readOneAirport(FILE* fp, Airport* airport) {
  /*
    Reads the next line of fp and puts the content in airport
    returns :
      - 0 if everything went well
      - 1 if end of file is reached
      - -1 if something is wrong with the data
  */
  // Retrieve the next line in a string
  char* line = malloc(sizeof(char) * MAX_LINE_LENGTH_AIRPORTS);
  if (retrieveNextLine(fp, &line, MAX_LINE_LENGTH_AIRPORTS) == 1)
    return 1;

  // We allocate a tmp buffer to use when the arguments are not strings and we
  // have to cast them to something else
  char* tmp = malloc(sizeof(char) * 20);
  char* next;
  char* curr = line;
  next = strchr(curr, ',');
  if (next == NULL) {
    free(line);
    return -1;
  }

  // We use atoi and atof to cast arguments to int and float respectively
  // When the arguments are strings, we just copy the content of the token to
  // the corresponding argument directly

  getNextArg(&curr, &next, &(airport->IATA_code), ',');
  getNextArg(&curr, &next, &(airport->name), ',');
  getNextArg(&curr, &next, &(airport->city), ',');
  getNextArg(&curr, &next, &(airport->state), ',');
  getNextArg(&curr, &next, &(airport->country), ',');

  getNextArg(&curr, &next, &tmp, ',');
  airport->longitude = atof(tmp);

  next = strchr(curr, '\0');
  strcpy(tmp, curr);
  tmp[next - curr + 1] = 0;
  airport->latitude = atof(tmp);

  free(line);
  free(tmp);
  return 0;
}

int readOneFlight(FILE* fp, Flight* f) {
  /*
    Reads the next line of fp and puts the content in f
    returns :
      - 0 if everything went well
      - 1 if end of file is reached
      - -1 if something is wrong with the data
  */
  // Retrieve the next line in a string
  char* line = malloc(sizeof(char) * MAX_LINE_LENGTH_FLIGHTS);
  if (retrieveNextLine(fp, &line, MAX_LINE_LENGTH_FLIGHTS) == 1)
    return 1;

  // We allocate a tmp buffer to use when the arguments are not strings and we
  // have to cast them to something else
  char* tmp = malloc(sizeof(char) * 20);
  char* next;
  char* curr = line;
  next = strchr(curr, ',');
  if (next == NULL) {
    free(line);
    return -1;
  }

  // We use atoi and atof to cast arguments to int and float respectively
  // When the arguments are strings, we just copy the content of the token to
  // the corresponding argument directly

  getNextArg(&curr, &next, &tmp, ',');
  f->month = atoi(tmp);
  getNextArg(&curr, &next, &tmp, ',');
  f->day = atoi(tmp);
  getNextArg(&curr, &next, &tmp, ',');
  f->weekday = atoi(tmp);

  getNextArg(&curr, &next, &(f->airline), ',');
  getNextArg(&curr, &next, &(f->org_air), ',');
  getNextArg(&curr, &next, &(f->dest_air), ',');

  getNextArg(&curr, &next, &tmp, ',');
  f->sched_dep = atoi(tmp);
  getNextArg(&curr, &next, &tmp, ',');
  f->dep_delay = atof(tmp);

  getNextArg(&curr, &next, &tmp, ',');
  f->air_time = atof(tmp);
  getNextArg(&curr, &next, &tmp, ',');
  f->dist = atoi(tmp);

  getNextArg(&curr, &next, &tmp, ',');
  f->sched_arr = atoi(tmp);
  getNextArg(&curr, &next, &tmp, ',');
  f->arr_delay = atof(tmp);

  getNextArg(&curr, &next, &tmp, ',');
  f->diverted = atoi(tmp) == 1;

  next = strchr(curr, '\0');
  strcpy(tmp, curr);
  tmp[next - curr + 1] = 0;
  f->canceled = atoi(tmp) == 1;

  free(line);
  free(tmp);
  return 0;
}