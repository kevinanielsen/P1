#ifndef search_H
#define search_H

#include "movie.h"

void searchGenre(Movie movies[], int movieCount, char *keyword, int *resultIndexes);
void searchTheme(Movie movies[], int movieCount, const char *keyword, int *resultIndexes);
int getMovieByTitle(Movie movies[], int movieCount, const char *title);
#endif
