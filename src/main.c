#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"
#include "hash.h"
#include "reader.h"
#include "sorter.h"

int main() {
  TableAirlines airlines;
  airlines.hash = &get_index_airlines;
  sortAirlines(&airlines);
  
  //ableAirports airports;
  //airlines.hash = &get_index_airports;
  sortAirports(/*&airports*/);
  sortFlights();
  return 0;
}

