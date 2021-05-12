#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void sortAirlines(HashtableAirlines* airlines) {
  FILE* fp = fopen(AIRLINES_PATH, "r"); 
  Airport token = blankAirline();
  int flag = 0;
  while ((flag = readOneAirline(fp, &token)) != 1) 
  { 
    if (flag != -1)
      airlines->content[airlines.hash(token.IATA_code)] = token; 
    
  }

}
