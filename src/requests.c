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
	BufferList seen;
	for (int i = 0; i<MAX_BUFFER_LEN; i++)
	{
		seen.content[i] = malloc(sizeof(char)*LEN_IATA_AIRPORT);
	}
	seen.last = -1;
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
	for (int i = 0; i<MAX_BUFFER_LEN; i++)
	{
		free(seen.content[i]);
	}
} 

void show_airlines(Tables* data, char* airport_id) {
	BufferList seen;
	for (int i = 0; i<MAX_BUFFER_LEN; i++)
	{
		seen.content[i] = malloc(sizeof(char)*LEN_IATA_AIRLINE);
	}
	seen.last = -1;
	for (int i = 0; i<DAYS_IN_HASHED_YEAR; i++)
	{
		for (int j = 0; j <= data->flights.dates[i].last; j++)
		{
			if (strcmp(data->flights.dates[i].content[j].org_air, airport_id) == 0)
			{
				if (notIn(seen, data->flights.dates[i].content[j].airline))
				{
					strcpy(seen.content[seen.last+1], data->flights.dates[i].content[j].airline);
					seen.last ++;
				}
			}
		}
	}
	for (int i = 0; i <= seen.last; i++)
	{
		printAirline(accessAirline(data->airlines, seen.content[i]));
	}
	for (int i = 0; i<MAX_BUFFER_LEN; i++)
	{
		free(seen.content[i]);
	}
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