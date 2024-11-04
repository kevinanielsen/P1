#include <stdio.h>
#include <string.h>
#include "movie.h"

void searchGenre(Movie movies[], int movieCount, char *keyword, int *searchedGenreIndex) {
    int foundCount = 0;
    int j = 0;
    for (int i = 0; i < movieCount; i++) {
        if (strstr(movies[i].genre, keyword) != NULL) {
            searchedGenreIndex[j] = i; 
            foundCount++;
            j++;
        }
    }
    if (foundCount == 0) {
        printf("No movies found with genre containing '%s'.\n", keyword);
    }
}

void searchTheme(Movie movies[], int movieCount, char *keyword, int *resultIndexes) {
    int foundCount = 0;
    int j = 0;
    for (int i = 0; i < movieCount; i++) {
        if (strstr(movies[i].theme, keyword) != NULL) {
            resultIndexes[j] = i;
            foundCount++;
            j++;
        }
    }
    if (foundCount == 0) {
        printf("No movies found with genre containing '%s'.\n", keyword);
    }
}
