#define MAX_LEN 100
#define LEN_IATA_AIRLINES 2
#define LEN_IATA_AIRPORTS 3

typedef struct Airline {
    char IATA_code[LEN_IATA_AIRLINES];
    char* name;
} Airline;

typedef struct Airport {
    char IATA_code[LEN_IATA_AIRPORTS];
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

    char airline[LEN_IATA_AIRLINES];
    char org_air[LEN_IATA_AIRPORTS];
    char dest_air[LEN_IATA_AIRPORTS];

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
