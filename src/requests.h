#define BOARDING_DELAY 30

void show_airports(Tables*, char*);
void show_airlines(Tables*, char*);
void show_flights(Tables*, char*, int, int, char*);
void most_delayed_flights(Tables*);
void most_delayed_airlines(Tables*);
void delayed_airline(Tables*, char*);
void most_delayed_airlines_at_airport(Tables*, char*);
void changed_flights(Tables*, int, int);
void avg_flight_duration(Tables*, char*, char*);
void find_itinerary(Tables*, char*, char*, int, int, char*);
void find_multicity_itinerary(Tables*, char*, QueueChars, QueueDates, QueueInts);