#ifndef movie_H
#define movie_H

#include "genres.h"

typedef struct Movie {
  int rank;
  char title[70];
  int sadness;
  char genre[100];
  char theme[100];
  int points;
} Movie;

void recommendMovies (Movie *movie);

#endif
