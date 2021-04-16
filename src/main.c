#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LEN 100

typedef struct Liste {
  void* l[MAX_LEN]
  int last;
} Liste;

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

  Airline airline;
  Airport org_air;
  Airport dest_air;

  int shed_dep;
  float dep_delay;

  float air_time;
  int dist;

  int shed_arr;
  float arr_delay;

  bool diverted;
  bool canceled;
} Flight;

typedef Airline companies[];

typedef struct Hashtable {


} Haschtable;
