#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "hash.h"
//#include "structures.h"
#include "reader.c"

int main() {
  FILE* fp = fopen("data/airports.csv", "r");
  //char* line = malloc(sizeof(char)*140);

  char* line = NULL;

  size_t n = 140;
  retrieveNextLine(fp, &line, n);
  printf("%s\n", line);
  free(line);
  fclose(fp);
}
