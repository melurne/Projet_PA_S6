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

int getcommand(Tables* data) {
	char* input = malloc(sizeof(char)*MAX_LENGTH_INPUT);
	char* args = malloc(sizeof(char)*MAX_LENGTH_ARGS);
	char* func = malloc(sizeof(char)*MAX_LENGTH_FUNCTION);

	retrieveNextLine(stdin, &input, MAX_LENGTH_INPUT);

	char* arg_start;
	if ((arg_start = strchr(input, " ")) != NULL)
	{
		strncpy(func, input, arg_start-input);
		strcpy(args, arg_start+1);
	}
	else
	{
		strcpy(func, input);
	}
/*
	switch (functionHash(func))
	{
		case HASH_show_airports:
			// Show_airports has only one argument so we can directly use args
			show_airports(data, args);

		case HASH_show_airlines:
			// Show_airlines has only one argument so we can directly use args
			show_airlines(data, args);

		case HASH_show_flights:
			char* curr = arg_start;
			char* next;
			if ((next = strchr(curr, " ")) == NULL)
			{
				free(input);
				free(args);
				free(func);
				return -1;
			}
			char* port_id = malloc(sizeof(char)*LEN_IATA_AIRPORT);
			strncpy(port_id, curr, curr-arg_start);
			curr = next+1;


			free(port_id);
	}*/

	free(input);
	free(args);
	free(func);
}
