// Hashes for the different functions were calculated manualy in advance
// We ca see that they are all indeed different, thus we should be able to use them effectively
#define HASH_show_airports 1378
#define HASH_show_airlines 1349
#define HASH_show_flights 1247
#define HASH_most_delayed_flights 2022
#define HASH_most_delayed_airlines 2124
#define HASH_delayed_airline 1513
#define HASH_most_delayed_airlines_at_airport 3196
#define HASH_changed_flights 1512
#define HASH_avg_flight_duration 1916
#define HASH_find_itinerary 1445
#define HASH_find_multicity_itinerary 2486
#define HASH_quit 451

int functionHash(const char*);
void extract_date(char*, int*, int*);
int getcommand(Tables*);
int exec_show_flights(Tables*, char*);
int exec_changed_flights(Tables*, char*);
int exec_avg_flight_duration(Tables*, char*);
int exec_find_itinerary(Tables*, char*);
int exec_find_multicity_itinerary(Tables*, char*);