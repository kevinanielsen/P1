#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "userSearch.h"
#define MAXCHAR 500

int userSearch(char *user) { // Indsætter værdier i structen for brugerens navn og en string med film-ratings.
  FILE *fp;
  fp = fopen("users.csv", "r"); // r - read mode
  if (fp == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  int counter = 0;
  char line[MAXCHAR];

  while (fgets(line, MAXCHAR, fp) != NULL && counter < 250) {
    if (sscanf(line, "%100[^,], %100[^\n]", userProfiles[counter].user, userProfiles[counter].userRatings) != 2) {
      printf("Error parsing line: %s\n", line);
      continue;
    }
    counter++;
  }
  fclose(fp);

  for (int j = 0; j < counter; j++) { // Finder indexet af den søgte bruger
    if (strcmp(user, userProfiles[j].user) == 0) {
      return j;
    }
  }

  return EXIT_FAILURE;
}

int stringToIntArray(char *str, int *array, int *size) { // Konverterer stringen med film-ratings til et array.
  char *token;
  int index = 0;

  token = strtok(str, ",");
  while (token != NULL && index < 100) {
    array[index++] = atoi(token);
    token = strtok(NULL, ",");
  }
  *size = index;

  return 0;
}
