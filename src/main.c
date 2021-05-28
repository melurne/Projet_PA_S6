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

  //Airline token = accessAirline(airlines, "AA");
  //printAirline(token);

  TableAirports airports;
  airports.hash = &get_index_airports;
  sortAirports(&airports);
  //printAirport(accessAirport(airports, "YUM"));

  TableFlights flights;
  flights.hash = hashDays;
  for (int i = 0; i<DAYS_IN_HASHED_YEAR; i++)
  {
    flights.dates[i].last = -1;
  }
  sortFlights(&flights);
  return 0;
}

