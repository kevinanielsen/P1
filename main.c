#include "dataLoad.h"
#include "movie.h"
#include "ratings.h"
#include "sadness.h"
#include "search.h"
#include "themes.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Movie movies[250];

  dataLoad(movies);

  int searchedGenreIndex[250];
  searchGenre(movies, 250, "Action", searchedGenreIndex);

  Ratings *ratings = rate10Movies();

  RatedTheme ratedThemes[25] = {0};
  scoreThemes(movies, ratedThemes, ratings);

  for (int i = 0; i < 25; i++) {
    printf("Theme: %s, Rating: %d\n", getThemeName(ratedThemes[i].theme),
           ratedThemes[i].rating);
  }

  Sadness mood;
  getMood(&mood);

  Genres genre;
  getGenre(&genre);
  printf("Genre: %s\n", getGenreName(genre));

  recommendMovies(movies);

  free(ratings);

  return 0;
}