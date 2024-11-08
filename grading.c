#include <stdio.h>
#include <stdlib.h>
#include "themes.h"
#include "movie.h"
#include "search.h"

void grading (RatedTheme ratedThemes[], Movie *movies){
    for (int i = 0; i < 20; i++) {
        char theme[50] = getThemeName(ratedThemes[i].theme);
        int resultIndexes[250];
        searchTheme(movies, 250, theme, *resultIndexes);

        for (int j = 0; j < 250; j++) {
            movies[resultIndexes[j]].points = ratedThemes[i].rating;
        }
    }

}

// Rating bliver spyttet ud i "movies

