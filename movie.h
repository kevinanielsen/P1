#ifndef movie_H
#define movie_H
#include "themes.h"
#include "genres.h"

typedef struct Movie {
  int rank;
  char title[70];
  int sadness;
  char genre[100];
  char theme[100];
  Themes themes[5];
  Genres genres[5];
  int points;
} Movie;

#endif
