#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"
#include "hash.h"
#include "reader.h"
#include "sorter.h"
#include "requests.h"

int main() {
  Tables data;
  data.airlines.hash = &get_index_airlines;
  sortAirlines(&(data.airlines));

  //Airline token = accessAirline(airlines, "AA");
  //printAirline(token);

  data.airports.hash = &get_index_airports;
  sortAirports(&(data.airports));
  //printAirport(accessAirport(airports, "YUM"));

  data.flights.hash = hashDays;
  for (int i = 0; i<DAYS_IN_HASHED_YEAR; i++)
  {
    data.flights.dates[i].last = -1;
  }
  sortFlights(&(data.flights));

  show_airports(&data, "HA");
  return 0;
}

