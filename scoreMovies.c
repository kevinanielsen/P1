#include "movie.h"
#include "search.h"
#include "themes.h"
#include <stdio.h>

void scoreMovies(Movie *movies, int movieCount, RatedTheme *ratedThemes,
                 int themeCount) {

  int resultIndexes[movieCount];
  for (int j = 0; j < themeCount; j++) {

    // Initialize all values to -1
    for (int i = 0; i < movieCount; i++) {
      resultIndexes[i] = -1;
    }

    searchTheme(movies, movieCount, getThemeName(ratedThemes[j].theme),
                resultIndexes);

    for (int i = 0; i < movieCount; i++) {
      if (resultIndexes[i] == -1)
        break;

      movies[resultIndexes[i]].points += ratedThemes[j].rating;
    }
  }
}
