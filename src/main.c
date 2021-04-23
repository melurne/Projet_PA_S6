#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

#define MAX_LEN 100

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

    int shed_dep;
    float dep_delay;

    float air_time;
    int dist;

    int shed_arr;
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

int main() {}
