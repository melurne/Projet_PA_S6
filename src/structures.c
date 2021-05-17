#include "structures.h"

void clearString(char str[], int size) {
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

  clearString(f.airline, LEN_IATA_AIRLINE+1);
  clearString(f.org_air, LEN_IATA_AIRPORT+1);
  clearString(f.dest_air, LEN_IATA_AIRPORT+1);

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
  clearString(airline.IATA_code, LEN_IATA_AIRLINE+1);
  clearString(airline.name, AIRLINES_NAME_BUFFER_LENGTH+1);
  
  printf("%s\n", airline.name);

  return airline;
}

Airport blankAirport() {
  // Initailizes all fields
  Airport airport;
  for (int i = 0; i<LEN_IATA_AIRPORT; i++)
  {
    airport.IATA_code[i] = '0';
  }
  /*
  strcpy(airport.name, "");
  strcpy(airport.city, "");
  strcpy(airport.state, "");
  strcpy(airport.country, "");
  */
  clearString(airport.name, AIRPORTS_NAME_BUFFER_LENGTH+1);
  clearString(airport.city, AIRPORTS_CITY_BUFFER_LENGTH+1);
  clearString(airport.state, AIRPORTS_STATE_BUFFER_LENGTH+1);
  clearString(airport.country, AIRPORTS_COUNTRY_BUFFER_LENGTH+1);

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
