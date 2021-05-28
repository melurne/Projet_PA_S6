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

  printf("testsuite: \n");

  printf("show_airports HA\n");
  show_airports(&data, "HA");

  printf("\nshow_airlines DFW\n");
  show_airlines(&data, "DFW");

  printf("\nshow_flights ATL 2-26\n");
  show_flights(&data, "ATL", 2, 26, "");

  printf("\nmost_delayed_flights\n");
  most_delayed_flights(&data);

  printf("\nmost_delayed_airlines\n");
  most_delayed_airlines(&data);

  return 0;
}

