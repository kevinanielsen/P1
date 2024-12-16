#ifndef SADNESS_H
#define SADNESS_H

#include "movie.h"

typedef enum Sadness {
  NO_SADNESS,
  MILD_SADNESS,
  MODERATE_SADNESS,
  SEVERE_SADNESS,
} Sadness;

void getMood(Sadness *mood);
const char *getMoodName(int mood);

int filterMoviesBySadness(Movie movies[], int movieIndexes[], int size,
                          Sadness highestSadness, int returnMovieIndexes[]);

#endif // SADNESS_H
