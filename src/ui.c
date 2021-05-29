#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"
#include "hash.h"
#include "reader.h"
#include "sorter.h"
#include "requests.h"
#include "ui.h"

int functionHash(const char* key) {
	int sum = 0;
	for (char* s = key; *s != 0; s++)
	{
		sum = sum + (int)(*s);
	}
	return sum;
}

void extract_date(char* date, int* month, int* day) {
	char* tmp = malloc(sizeof(char)*3);
	char* curr = date;
	char* next = strchr(date, '-');
	strncpy(tmp, curr, next-curr);
	tmp[next-curr] = 0;
	*month = atoi(tmp);
	*day = atoi(next+1);

	free(tmp);
}

int exec_show_flights(Tables* data, char* args) {
	int month, day;

	char* curr = args;
	char* next;
	if ((next = strchr(curr, ' ')) == NULL)
	{
		return -1;
	}
	char* date = malloc(sizeof(char)*6);
	char* port_id = malloc(sizeof(char)*LEN_IATA_AIRPORT);
	strncpy(port_id, curr, next-curr);
	port_id[next-curr] = 0;
	curr = next+1;
	// Only port_id and date were passed
	if ((next = strchr(curr, ' ')) == NULL)
	{
		strcpy(date, curr);
		extract_date(date, &month, &day);
		show_flights(data, port_id, month, day, "");
		free(date);
		free(port_id);
		return 0;
	}
	strncpy(date, curr, next-curr);
	date[next-curr] = 0;
	curr = next+1;
	extract_date(date, &month, &day);
	show_flights(data, port_id, month, day, curr);

	free(date);
	free(port_id);
	return 0;
}

int exec_changed_flights(Tables* data, char* args) {
	int month, day;
	extract_date(args, &month, &day);
	changed_flights(data, month, day);
	return 0;
}

int exec_avg_flight_duration(Tables* data, char* args) {
	char* curr = args;
	char* next;
	if ((next = strchr(curr, ' ')) == NULL)
	{
		return -1;
	}
	char* port_id1 = malloc(sizeof(char)*LEN_IATA_AIRPORT);
	char* port_id2 = malloc(sizeof(char)*LEN_IATA_AIRPORT);
	strncpy(port_id1, curr, next-curr);
	port_id1[next-curr] = 0;
	strcpy(port_id2, next+1);

	avg_flight_duration(data, port_id1, port_id2);

	free(port_id1);
	free(port_id2);
	return 0;
}

int getcommand(Tables* data) {
	char* input = malloc(sizeof(char)*MAX_LENGTH_INPUT);

	if (retrieveNextLine(stdin, &input, MAX_LENGTH_INPUT) == 1)
	{
		free(input);
		return 1;
	}
	char* args = malloc(sizeof(char)*MAX_LENGTH_ARGS);
	char* func = malloc(sizeof(char)*MAX_LENGTH_FUNCTION);

	printf("\n%s\n", input);

	char* arg_start;
	if ((arg_start = strchr(input, ' ')) != NULL)
	{
		strncpy(func, input, arg_start-input);
		func[arg_start-input] = 0;
		strcpy(args, arg_start+1);
		//printf("%s\n", args);
	}
	else
	{
		strcpy(func, input);
	}

	//printf("%s\n", arg_start);
	//printf("%s\n", func);
	//printf("%d\n", functionHash(func));
	int result = 0;
	switch (functionHash(func))
	{
		case HASH_show_airports:
			// Show_airports has only one argument so we can directly use args
			show_airports(data, args);
			result = 0;
			break;

		case HASH_show_airlines:
			// Show_airlines has only one argument so we can directly use args
			show_airlines(data, args);
			result = 0;
			break;

		case HASH_show_flights:
			// Here we need to parse the arguments, we need to seperate the function for this because of the switch statement
			result = exec_show_flights(data, args);
			break;

		case HASH_most_delayed_flights:
			// most_delayed_flights takes no arguments so we can use it directly
			most_delayed_flights(data);
			result = 0;
			break;

		case HASH_most_delayed_airlines:
			// Same as most_delayed_flights
			most_delayed_airlines(data);
			result = 0;
			break;

		case HASH_delayed_airline:
			// delayed_airline has only one argument so we can directly use args
			delayed_airline(data, args);
			result = 0;
			break;

		case HASH_most_delayed_airlines_at_airport:
			// most_delayed_airlines_at_airport has only one argument so we can directly use args
			most_delayed_airlines_at_airport(data, args);
			result = 0;
			break;

		case HASH_changed_flights:
			// changed_flights takes a date which we need to parse first
			result = exec_changed_flights(data, args);
			break;

		case HASH_avg_flight_duration:
			// avg_flight_duration takes two arguments which need to be parsed
			result = exec_avg_flight_duration(data, args);
			break;

		case HASH_quit:
			result = 1;
			break;

		default :
			result = -2;
			break;

	}

	free(input);
	free(args);
	free(func);
	//printf("%d\n", result);
	return result;
}
