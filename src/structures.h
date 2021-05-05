#include <stdbool.h>

#define MAX_LEN 100

#define MASK_FLIGHTS "%d %d %d %s %s %s %d %f %f %d %d %f %d %d"
#define MASK_FLIGHTS_MISSING "%d %d %d %s %s %s %d   %d %d  %d %d"
#define NARGS_FLIGHTS 14
#define NARGS_FLIGHTS_MIN 11
#define MAX_LINE_LENGTH_FLIGHTS 70

#define MASK_AIRLINES "%s %s"
#define NARGS_AIRLINES 2
#define LEN_IATA_AIRLINE 2
#define MAX_LINE_LENGTH_AIRLINES 40
#define MAX_LEN_AIRLINES 20 

#define MASK_AIRPORTS "%s %s %s %s %s %f %f"
#define NARGS_AIRPORTS 7
#define NARGS_AIRPORTS_MIN 5
#define LEN_IATA_AIRPORT 3
#define MAX_LINE_LENGTH_AIRPORTS 140
#define MAX_LEN_AIRPORTS 350  

typedef struct Airline {
    char IATA_code[LEN_IATA_AIRLINE];
    char* name;
} Airline;

typedef struct Airport {
    char IATA_code[LEN_IATA_AIRPORT];
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

    char airline[LEN_IATA_AIRLINE];
    char org_air[LEN_IATA_AIRPORT];
    char dest_air[LEN_IATA_AIRPORT];

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
  int (*hash)(char*);
} TableAirlines;

typedef struct HashtableAirports {
  Airport content[MAX_LEN_AIRPORTS];
  int (*hash)(char*);
} TableAirports;

void printIATA(char[], int);
Flight blankFlight();
Airline blankAirline();
Airport blankAirport();
void printAirline(Airline);
void printAirport(Airport);
void printFlight(Flight);

TableAirports airports;
TableAirlines airlines;

