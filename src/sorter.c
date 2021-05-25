#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "hash.h"
#include "structures.h"
#include "reader.h"
#include "sorter.h"

void sortAirlines(TableAirlines* airlines) {
  FILE* fp = fopen(AIRLINES_PATH, "r"); 
  Airline token = blankAirline();
  printf("test\n");
  int flag = 0;
  
  char* line = NULL;
  retrieveNextLine(fp, &line, MAX_LINE_LENGTH_AIRLINES);
  while ((flag = readOneAirline(fp, &token)) != 1) 
  { 
    flag = 0;
    //if (flag != -1)
      //airlines->content[airlines->hash(token.IATA_code)] = token;    
  }
  fclose(fp);
  printf("fin\n");
}

void sortAirports(/*TableAirports* airports*/) {
  FILE* fp = fopen("data/airports.csv", "r"); 
  Airport token = blankAirport();
  printf("test\n");
  int flag = 0;
  
  char* line = NULL;
  retrieveNextLine(fp, &line, MAX_LINE_LENGTH_AIRPORTS);
  while ((flag = readOneAirport(fp, &token)) != 1) 
  { 
    flag = 0;
    //if (flag != -1)
      //airlines->content[airlines->hash(token.IATA_code)] = token;    
  }
  fclose(fp);
  printf("fin\n");
}

void sortFlights(/*TableAirports* airports*/) {
  FILE* fp = fopen("data/flights.csv", "r"); 
  Flight token = blankFlight();
  printf("test\n");
  int flag = 0;
  
  char* line = NULL;
  retrieveNextLine(fp, &line, MAX_LINE_LENGTH_FLIGHTS);
  while ((flag = readOneFlight(fp, &token)) != 1) 
  { 
    flag = 0;
    //if (flag != -1)
      //airlines->content[airlines->hash(token.IATA_code)] = token;    
  }
  fclose(fp);
  printf("fin\n");
}
