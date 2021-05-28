#include <stdbool.h>

#define MAX_LEN 200
#define DAYS_IN_HASHED_YEAR (12-1)*31 + 31 // = 372 or just 6 more than a leap year
#define MAX_BUFFER_LEN 300
#define TMP_BUFFER_SIZE 20

#define SEPARATOR ','

#define MASK_FLIGHTS "%d %d %d %s %s %s %d %f %f %d %d %f %d %d"
#define MASK_FLIGHTS_MISSING "%d %d %d %s %s %s %d   %d %d  %d %d"
#define NARGS_FLIGHTS 14
#define NARGS_FLIGHTS_MIN 11
#define MAX_LINE_LENGTH_FLIGHTS 70
#define FLIGHTS_PATH "data/flights.csv"

//#define MASK_AIRLINES "%s\t%s"
//#define MASK_AIRLINES {'s', 's'}
#define NARGS_AIRLINES 2
#define LEN_IATA_AIRLINE 2
#define MAX_LINE_LENGTH_AIRLINES 40
#define MAX_LEN_AIRLINES 20 
#define AIRLINES_PATH "data/airlines.csv"
#define AIRLINES_NAME_BUFFER_LENGTH 30

#define MASK_AIRPORTS "%s %s %s %s %s %f %f"
#define NARGS_AIRPORTS 7
#define NARGS_AIRPORTS_MIN 5
#define LEN_IATA_AIRPORT 3
#define MAX_LINE_LENGTH_AIRPORTS 140
#define MAX_LEN_AIRPORTS 350  
#define AIRPORTS_PATH "data/airports.csv"
#define AIRPORTS_NAME_BUFFER_LENGTH 75
#define AIRPORTS_CITY_BUFFER_LENGTH 20
#define AIRPORTS_STATE_BUFFER_LENGTH 5
#define AIRPORTS_COUNTRY_BUFFER_LENGTH 5

typedef struct Airline {
  char* IATA_code;
  char* name;
} Airline;

typedef struct Airport {
  char* IATA_code;
  char* name;

  char* city;
  char* state;
  char* country;

  float latitude;
  float longitude;
} Airport;

typedef struct Flight {
  int month;
  int day;
  int weekday;

  char* airline;
  char* org_air;
  char* dest_air;

  int sched_dep;
  float dep_delay;

  float air_time;
  int dist;

  int sched_arr;
  float arr_delay;

  bool diverted;
  bool canceled;
} Flight;

typedef struct FlightsOnDay {
  //int month;
  //int day;
  Flight content[MAX_LEN];
  int last;
} FlightsOnDay;

typedef struct TableFlights {
  FlightsOnDay dates[DAYS_IN_HASHED_YEAR];
  int (*hash)(const int, const int);
} TableFlights;

typedef struct HashtableAirlines {
  Airline content[MAX_LEN_AIRLINES];
  int (*hash)(const char*);
} TableAirlines;

typedef struct HashtableAirports {
  Airport content[MAX_LEN_AIRPORTS];
  int (*hash)(const char*);
} TableAirports;

typedef struct BufferList {
  char* content[MAX_BUFFER_LEN];
  int last;
} BufferList;

typedef struct Tables {
  TableAirports airports;
  TableAirlines airlines;
  TableFlights flights;
} Tables;

typedef struct stats {
  char* IATA_code;
  float sum;
  int count;
} stats;

typedef struct statAirlines {
  stats content[MAX_LEN_AIRLINES];
  int (*hash)(const char*);
} statAirlines;

void clearString(char*); 
void printIATA(char[], int);

Flight blankFlight();
Airline blankAirline();
Airport blankAirport();

void printAirline(Airline);
void printAirport(Airport);
void printFlight(Flight);

int hashDays(const int, const int);

int compareFlight(Flight, Flight);

void addFlight(FlightsOnDay*, Flight);

void insertAirline(TableAirlines*, Airline);
void insertAirport(TableAirports*, Airport);
void insertFlight(TableFlights*, Flight);

Airline accessAirline(TableAirlines, const char*);
Airport accessAirport(TableAirports, const char*);
FlightsOnDay listFlightsByDate(TableFlights, int, int);

bool notIn(BufferList, char*);
BufferList initBuffer();
void freeBuffer(BufferList);
void insertBuffer(BufferList*, char*);

void index_min_arr_delay(Flight[5], int*, float*);