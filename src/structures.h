#include <stdbool.h>

#define MAX_LEN 100

#define MASK_FLIGHTS "dddsssdffddfdd"
#define NARGS_FLIGHTS 14
#define NARGS_FLIGHTS_MIN 11
#define MAX_LINE_LENGTH_FLIGHTS 70

#define MASK_AIRLINES "ss"
#define NARGS_AIRLINES 2
#define MAX_LINE_LENGTH_AIRLINES 40

#define MASK_AIRPORTS "sssssff"
#define NARGS_AIRPORTS 7
#define MAX_LINE_LENGTH_AIRPORTS 140


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

    char airline[2];
    char org_air[3];
    char dest_air[3];

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

} TableAirlines;

typedef struct HashtableAirports {
} TableAirports;

Flight blankFlight();
void printFlight(Flight f);
