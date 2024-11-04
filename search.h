#ifndef search_H
#define search_H

#include "movie.h"

void searchGenre(const Movie movies[], int movieCount, const char *keyword);
void searchTheme(const Movie movies[], int movieCount, const char *keyword);
#endif