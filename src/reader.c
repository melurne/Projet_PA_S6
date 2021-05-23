#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"

void formatStr(char* string) {
  /*
    Replaces all ',' in string with whitespaces
    to allow formating using %s in sscanf
  */
  char* current_pos = strchr(string,'\n');
  *current_pos = 0;
}

int retrieveNextLine(FILE* fp, char* line, size_t max_lenght_line) {
  if (getline(&line, &max_lenght_line, fp) == -1)
    // If the end of file has been reached, return 1
    return 1;

  formatStr(line);
  return 0;
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
  char* line = malloc(sizeof(char)*MAX_LINE_LENGTH_AIRLINES);
  if (retrieveNextLine(fp, line, MAX_LINE_LENGTH_AIRLINES) == 1)
    return 1;


  char *next;
  char *curr = line;
  next = strchr(curr, ',');
  if (next == NULL)
  {
    free(line);
    return -1;
  }

  memcpy(airline->IATA_code, curr, next-curr);
  curr = next + 1;

  next = strchr(curr, ',');
  memcpy(airline->name, curr, next-curr);

  printf("%s %s\n", airline->IATA_code, airline->name);
  free(line);
	return 0;
}