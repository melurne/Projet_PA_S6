#include "sorter.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#include "reader.h"
#include "structures.h"

void sortAirlines(TableAirlines* airlines) {
  FILE* fp = fopen(AIRLINES_PATH, "r");
  Airline token = blankAirline();
  // printf("Airlines start\n");
  int flag = 0;

  char* line = NULL;
  retrieveNextLine(fp, &line, MAX_LINE_LENGTH_AIRLINES);
  while ((flag = readOneAirline(fp, &token)) != 1) {
    if (flag != -1)
      insertAirline(airlines, token);
    // We reset token to avoid all elements of content being the same due to
    // pointers
    token = blankAirline();
  }
  fclose(fp);
  // printf("Airlines end\n");
}

void sortAirports(TableAirports* airports) {
  FILE* fp = fopen("data/airports.csv", "r");
  Airport token = blankAirport();
  // printf("Airports start\n");
  int flag = 0;

  char* line = NULL;
  retrieveNextLine(fp, &line, MAX_LINE_LENGTH_AIRPORTS);
  while ((flag = readOneAirport(fp, &token)) != 1) {
    if (flag != -1)
      insertAirports(airports, token);
    // We reset token to avoid all elements of content being the same due to
    // pointers
    token = blankAirport();
  }
  fclose(fp);
  // printf("Airports end\n");
}

void sortFlights(TableFlights* flights) {
  FILE* fp = fopen("data/flights.csv", "r");
  Flight token = blankFlight();
  // printf("Flights start\n");
  int flag = 0;

  char* line = NULL;
  retrieveNextLine(fp, &line, MAX_LINE_LENGTH_FLIGHTS);
  while ((flag = readOneFlight(fp, &token)) != 1) {
    if (flag != -1)
      insertFlight(flights, token);
    // We reset token to avoid all elements of the tree being the same due
    // to pointers
    token = blankFlight();
  }
  fclose(fp);
  // printf("Airports end\n");
}
