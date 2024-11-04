#ifndef search_H
#define search_H

#include "movie.h"

void searchGenre(Movie movies[], int movieCount, char *keyword);
void searchTheme(const Movie movies[], int movieCount, const char *keyword);
#endif