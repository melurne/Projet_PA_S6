#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "hash.h"
#include "structures.h"
#include "reader.h"
#include "sorter.h"
#include "requests.h"

void show_airports(Tables* data, char* airline_id) {
	BufferList seen = initBuffer();
	for (int i = 0; i<DAYS_IN_HASHED_YEAR; i++)
	{
		for (int j = 0; j <= data->flights.dates[i].last; j++)
		{
			if (strcmp(data->flights.dates[i].content[j].airline, airline_id) == 0)
			{
				if (notIn(seen, data->flights.dates[i].content[j].org_air))
				{
					strcpy(seen.content[seen.last+1], data->flights.dates[i].content[j].org_air);
					seen.last ++;
				}
				if (notIn(seen, data->flights.dates[i].content[j].dest_air))
				{
					strcpy(seen.content[seen.last+1], data->flights.dates[i].content[j].dest_air);
					seen.last ++;
				}
			}
		}
	}
	for (int i = 0; i <= seen.last; i++)
	{
		printAirport(accessAirport(data->airports, seen.content[i]));
	}
	freeBuffer(seen);
} 

void show_airlines(Tables* data, char* airport_id) {
	BufferList seen = initBuffer();
	for (int i = 0; i<DAYS_IN_HASHED_YEAR; i++)
	{
		for (int j = 0; j <= data->flights.dates[i].last; j++)
		{
			if (strcmp(data->flights.dates[i].content[j].org_air, airport_id) == 0)
			{
				if (notIn(seen, data->flights.dates[i].content[j].airline))
				{
					insertBuffer(&seen, data->flights.dates[i].content[j].airline);
				}
			}
		}
	}
	for (int i = 0; i <= seen.last; i++)
	{
		printAirline(accessAirline(data->airlines, seen.content[i]));
	}
	freeBuffer(seen);
}

void show_flights(Tables* data, char* port_id, int month, int day, char* optionnal_args) {
	int time = 0;
	int cap = MAX_LEN;
	if (optionnal_args != "")
	{
		char* curr = strchr(optionnal_args, " ");
		// A single optionnal argument has been passed
		if (curr == NULL)
		{
			// A time has benn passed
			if ((curr = strchr(optionnal_args, "=")) == NULL)
			{
				time = atoi(optionnal_args);
			}
			// A limit has been passed
			else
			{
				cap = atoi(curr+1);
			}
		}
		// Both arguments have been passed
		else
		{
			char* tmp = malloc(sizeof(char)*TMP_BUFFER_SIZE);
			strncpy(tmp, optionnal_args, optionnal_args-curr);
			time = atoi(tmp);
			curr = strchr(optionnal_args, "=");
			cap = atoi(curr+1);
			free(tmp);
		}
	}

	int count=0;

	FlightsOnDay timeScale = data->flights.dates[data->flights.hash(month, day)];
	for (int i = 0; i < timeScale.last && count < cap; i++)
	{
		if (strcmp(timeScale.content[i].org_air, port_id) == 0 && timeScale.content[i].sched_dep > time)
		{
			count++;
			printFlight(timeScale.content[i]);
		}
	}
}

void most_delayed_flights(Tables* data) {
	Flight most_delayed[5];
	int index_smallest = 0;
	float min_delay = 0;
	for (int i = 0; i < 5; i++)
	{
		most_delayed[i] = blankFlight();
	}
	for (int i = 0; i<DAYS_IN_HASHED_YEAR; i++)
	{
		for (int j = 0; j <= data->flights.dates[i].last; j++)
		{
			if (data->flights.dates[i].content[j].arr_delay > min_delay)
			{
				most_delayed[index_smallest] = data->flights.dates[i].content[j];
				index_min_arr_delay(most_delayed, &index_smallest, &min_delay);
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		printFlight(most_delayed[i]);
	}
}

void most_delayed_airlines(Tables* data) {
	statAirlines averages;
	averages.hash = &get_index_airlines;
	for (int i = 0; i<MAX_LEN_AIRLINES; i++)
	{
		averages.content[i].sum = 0;
		averages.content[i].count = 0;
		averages.content[i].IATA_code = malloc(sizeof(char)*MAX_LEN_AIRLINES);
	}

	for (int i = 0; i<DAYS_IN_HASHED_YEAR; i++)
	{
		for (int j = 0; j <= data->flights.dates[i].last; j++)
		{
			if (!(data->flights.dates[i].content[j].diverted || data->flights.dates[i].content[j].canceled))
			{
				strcpy(averages.content[averages.hash(data->flights.dates[i].content[j].airline)].IATA_code, data->flights.dates[i].content[j].airline);
				averages.content[averages.hash(data->flights.dates[i].content[j].airline)].sum = 	averages.content[averages.hash(data->flights.dates[i].content[j].airline)].sum
																																													+ data->flights.dates[i].content[j].arr_delay; 
				averages.content[averages.hash(data->flights.dates[i].content[j].airline)].count++;
			}
		}
	}

	for (int i = 0; i<MAX_LEN_AIRLINES; i++)
	{
		if (averages.content[i].count != 0)
			averages.content[i].sum = averages.content[i].sum / averages.content[i].count;
	}

	float max = 0;
	int id_max = 0;
	for (int j = 0; j<5; j++)
	{
		max = averages.content[0].sum;
		id_max = 0;
		for (int i = 0; i<MAX_LEN_AIRLINES; i++)
		{
			if (averages.content[i].count != 0 && averages.content[i].sum > max)
			{
				max = averages.content[i].sum;
				id_max = i;
			}
		}
		// We have the current maximum average
		printAirline(accessAirline(data->airlines, averages.content[id_max].IATA_code));
		// We put the maximum average to 0 in order to ignore it on te next pass
		averages.content[id_max].sum = 0;
	}
	for (int i = 0; i<MAX_LEN_AIRLINES; i++)
	{
		free(averages.content[i].IATA_code);
	}
}