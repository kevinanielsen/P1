#include "dataLoad.h"
#include "movie.h"
#include "ratings.h"
#include "sadness.h"
#include "scoreMovies.h"
#include "search.h"
#include "themes.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Movie movies[250];

  dataLoad(movies);

  int searchedGenreIndex[250];

  Ratings *ratings = rate10Movies();

  RatedTheme ratedThemes[25] = {0};
  scoreThemes(movies, ratedThemes, ratings);
  scoreMovies(movies, 250, ratedThemes, 25);

  for (int i = 0; i < 25; i++) {
    printf("Theme: %s, Rating: %d\n", getThemeName(ratedThemes[i].theme),
           ratedThemes[i].rating);
  }

  Sadness mood;
  getMood(&mood);

  Genres genre;
  getGenre(&genre);

  printf("Genre: %s\n", getGenreName(genre));

  searchGenre(movies, 250, getGenreName(genre), searchedGenreIndex);

  int matchCount = 0;
  while (searchedGenreIndex[matchCount] != 0 && matchCount < 250) {
    matchCount++;
  }

  recommendMovies(movies, searchedGenreIndex, matchCount);

  free(ratings);

  return 0;
}
