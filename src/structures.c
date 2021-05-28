#include <stdlib.h>
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
  printf("%s,%s\n", airline.IATA_code, airline.name);
}

void printAirport(Airport airport) {
  printf( "%s,%s,%s,%s,%s,%f,%f\n", 
          airport.IATA_code, 
          airport.name, 
          airport.city, 
          airport.state, 
          airport.country, 
          airport.latitude, 
          airport.longitude);
}

void printFlight(Flight f) {
  if (f.diverted || f.canceled)
    printf( "%d,%d,%d,%s,%s,%s,%d,,,%d,%d,,%d,%d\n", 
          f.month,
          f.day,
          f.weekday,
          f.airline,
          f.org_air,
          f.dest_air,
          f.sched_dep,
          f.dist,
          f.sched_arr,
          f.diverted ? 1 : 0,
          f.canceled ? 1 : 0);
  else
    printf( "%d,%d,%d,%s,%s,%s,%d,%f,%f,%d,%d,%f,%d,%d\n", 
          f.month,
          f.day,
          f.weekday,
          f.airline,
          f.org_air,
          f.dest_air,
          f.sched_dep,
          f.dep_delay,
          f.air_time,
          f.dist,
          f.sched_arr,
          f.arr_delay,
          f.diverted ? 1 : 0,
          f.canceled ? 1 : 0);
}

int hashDays(const int month, const int day) {
  // We subtract 1 to begin the list at index 0
  return (month-1)*31 + day - 1;
}

int compareFlight(Flight f1, Flight f2) {
  if ((f1.month*100 + f1.day) > (f2.month*100 + f2.day))
    return 1;
  else if ((f1.month*100 + f1.day) == (f2.month*100 + f2.day))
    return 0;
  else 
    return -1;
}

void addFlight(FlightsOnDay* ptList, Flight token) {
  ptList->content[ptList->last+1] = token;
  ptList->last ++;
}

void insertAirline(TableAirlines* airlines, Airline token) {
  airlines->content[airlines->hash(token.IATA_code)] = token;
}

void insertAirports(TableAirports* airports, Airport token) {
  airports->content[airports->hash(token.IATA_code)] = token;
}

void insertFlight(TableFlights* flights, Flight token) {
  addFlight(&(flights->dates[flights->hash(token.month, token.day)]), token);
}

Airline accessAirline(TableAirlines airlines, const char* key) {
  return airlines.content[airlines.hash(key)];
}

Airport accessAirport(TableAirports airports, const char* key) {
  return airports.content[airports.hash(key)];
}

FlightsOnDay listFlightsByDate(TableFlights flights, int month, int day) {
  return flights.dates[flights.hash(month, day)];
}

bool notIn(BufferList list, char* token) {
  for (int i = 0; i <= list.last; i++)
  {
    if (strcmp(list.content[i], token) == 0)
    {
      return false;
    }
  }
  return true;
}

BufferList initBuffer() {
  BufferList list;
  for (int i = 0; i<MAX_BUFFER_LEN; i++)
  {
    list.content[i] = malloc(sizeof(char)*LEN_IATA_AIRLINE);
  }
  list.last = -1;
  return list;
}

void freeBuffer(BufferList list) {
  for (int i = 0; i<MAX_BUFFER_LEN; i++)
  {
    free(list.content[i]);
  }
}

void insertBuffer(BufferList* list, char* token) {
  strcpy(list->content[list->last+1], token);
  list->last ++;
}

void index_min_arr_delay(Flight list[5], int* id_min, float* min) {
  *min = list[0].arr_delay;
  *id_min = 0;
  for (int i = 1; i < 5; i++)
  {
    if (list[i].arr_delay < *min)
    {
      *min = list[i].arr_delay;
      *id_min = i;
    }
  }
}