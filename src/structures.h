#include <stdbool.h>

#define MAX_LEN 100

#define MASK_FLIGHTS "%d %d %d %s %s %s %d %f %f %d %d %f %d %d"
#define MASK_FLIGHTS_MISSING "%d %d %d %s %s %s %d   %d %d  %d %d"
#define NARGS_FLIGHTS 14
#define NARGS_FLIGHTS_MIN 11
#define MAX_LINE_LENGTH_FLIGHTS 70
#define FLIGHTS_PATH "data/flights.csv"

#define MASK_AIRLINES "%s\t%s"
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
    char IATA_code[LEN_IATA_AIRLINE+1];
    char name[AIRLINES_NAME_BUFFER_LENGTH+1];
} Airline;

typedef struct Airport {
    char IATA_code[LEN_IATA_AIRPORT+1];
    char name[AIRPORTS_NAME_BUFFER_LENGTH+1];

    char city[AIRPORTS_CITY_BUFFER_LENGTH+1];
    char state[AIRPORTS_STATE_BUFFER_LENGTH+1];
    char country[AIRPORTS_COUNTRY_BUFFER_LENGTH+1];

    float latitude;
    float longitude;
} Airport;

typedef struct Flight {
    int month;
    int day;
    int weekday;

    char airline[LEN_IATA_AIRLINE+1];
    char org_air[LEN_IATA_AIRPORT+1];
    char dest_air[LEN_IATA_AIRPORT+1];

    int sched_dep;
    float dep_delay;

    float air_time;
    int dist;

    int sched_arr;
    float arr_delay;

    bool diverted;
    bool canceled;
} Flight;

typedef struct ListFlights {
    void* l[MAX_LEN];
    int last;
} Liste;

typedef struct HashtableAirlines {
  Airline content[MAX_LEN_AIRLINES];
  int (*hash)(const char*);
} TableAirlines;

typedef struct HashtableAirports {
  Airport content[MAX_LEN_AIRPORTS];
  int (*hash)(const char*);
} TableAirports;

void clearString(char[], int); 
void printIATA(char[], int);
Flight blankFlight();
Airline blankAirline();
Airport blankAirport();
void printAirline(Airline);
void printAirport(Airport);
void printFlight(Flight);
