#include "structures.h"

void clearString(char* str) {
  /*
  for (int i = 0; i < size-1; i++)
  {
    str[i] = '.';
  }
  str[size-1] = '\0';
  */
  str[0] = '0';
  str[1] = '\0';
}

void printIATA(char iata[], int size) {
  for (int i = 0; i<size; i++)
  {
    printf("%c", iata[i]);
  }
}

Flight blankFlight() {
  // Initailizes all fields to 0
  Flight f;
  f.month = 0;
  f.day = 0;
  f.weekday = 0;

  f.airline = malloc(sizeof(char)*LEN_IATA_AIRLINE);
  f.org_air = malloc(sizeof(char)*LEN_IATA_AIRPORT);
  f.dest_air = malloc(sizeof(char)*LEN_IATA_AIRPORT);

  clearString(f.airline);
  clearString(f.org_air);
  clearString(f.dest_air);

  f.sched_dep = 0000;
  f.dep_delay = 0.;

  f.air_time = 0.;
  f.dist = 0;

  f.sched_arr = 0000;
  f.arr_delay = 0.;

  f.diverted = false;
  f.canceled = false;

  return f;
}

Airline blankAirline() {
  // Initailizes all fields
  Airline airline;
  airline.IATA_code   = malloc(sizeof(char)*LEN_IATA_AIRLINE);
  airline.name        = malloc(sizeof(char)*AIRLINES_NAME_BUFFER_LENGTH);

  clearString(airline.IATA_code);
  clearString(airline.name);
  
  printf("%s\n", airline.name);

  return airline;
}

Airport blankAirport() {
  // Initailizes all fields
  Airport airport;

  airport.IATA_code = malloc(sizeof(char)*LEN_IATA_AIRPORT);
  airport.name = malloc(sizeof(char)*AIRPORTS_NAME_BUFFER_LENGTH);
  airport.city = malloc(sizeof(char)*AIRPORTS_CITY_BUFFER_LENGTH);
  airport.state = malloc(sizeof(char)*AIRPORTS_STATE_BUFFER_LENGTH);
  airport.country = malloc(sizeof(char)*AIRPORTS_COUNTRY_BUFFER_LENGTH);

  clearString(airport.IATA_code);
  clearString(airport.name);
  clearString(airport.city);
  clearString(airport.state);
  clearString(airport.country);

  airport.latitude = 0.;
  airport.longitude = 0.;
  return airport;
}

void printAirline(Airline airline) {
  printIATA(airline.IATA_code, LEN_IATA_AIRLINE);
  printf(',');
  printf("%s\n", airline.name);
}

void printAirport(Airport airport) {
  printIATA(airport.IATA_code, LEN_IATA_AIRPORT);
  printf(",");
  printf("%s", airport.name);
  printf(",");
  printf("%s", airport.city);
  printf(",");
  printf("%s", airport.state);
  printf(",");
  printf("%s", airport.country);
  printf(",");
  printf("%f,", airport.latitude);
  printf("%f\n", airport.longitude);
}

void printFlight(Flight f) {
  printf("%d,", f.month);
  printf("%d,", f.day);
  printf("%d,", f.weekday);
  printIATA(f.airline, LEN_IATA_AIRLINE);
  printf(",");
  printIATA(f.org_air, LEN_IATA_AIRPORT);
  printf(",");
  printIATA(f.dest_air, LEN_IATA_AIRPORT);
  printf(",");
  printf("%d,", f.sched_dep);
  printf("%f,", f.dep_delay);
  printf("%f,", f.air_time);
  printf("%d,", f.dist);
  printf("%d,", f.sched_arr);
  printf("%f,", f.arr_delay);
  printf("%d,", f.diverted ? 1 : 0);
  printf("%d\n", f.canceled ? 1 : 0);
}
