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
  int flag = 0;
  while ((flag = readOneAirline(fp, &token)) != 1) 
  { 
    if (flag != -1)
      airlines->content[airlines->hash(token.IATA_code)] = token;    
  }
}
