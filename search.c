#include <stdio.h>
#include <string.h>
#include "movie.h"



void searchGenre(const Movie movies[], int movieCount, const char *keyword) {
    int foundCount = 0;

    for (int i = 0; i < movieCount; i++) {
        if (strstr(movies[i].genre, keyword) != NULL) {
            printf("Movie: %s, Genre: %s\n", movies[i].title, movies[i].genre);
            foundCount++;
        }
    }

    if (foundCount == 0) {
        printf("No movies found with genre containing '%s'.\n", keyword);
    }
}

void searchTheme(const Movie movies[], int movieCount, const char *keyword) {
    int foundCount = 0;

    for (int i = 0; i < movieCount; i++) {
        if (strstr(movies[i].theme, keyword) != NULL) {
            printf("Movie: %s, Theme: %s\n", movies[i].title, movies[i].theme);
            foundCount++;
        }
    }

    if (foundCount == 0) {
        printf("No movies found with genre containing '%s'.\n", keyword);
    }
}