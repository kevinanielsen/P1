#include "dataLoad.h"
#include "genres.h"
#include "movie.h"
#include "ratings.h"
#include "sadness.h"
#include "search.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Movie movie[250];

  dataLoad(movie);

  int searchedGenreIndex[250];
  searchGenre(movie, 250, "Action", searchedGenreIndex);

  // searchTheme(movie, 250, "Fear");

  printf(
      "Made by: Elias, Isabella, Kevin, Mathias, Matilde, Oliver, Tobias \n");

  Ratings *ratings = malloc(10 * sizeof(Ratings));
  ratings = rate10Movies();

  Sadness mood;
  getMood(&mood);

  Genres genre;
  getGenre(&genre);
  printf("Genre: %s\n", getGenreName(genre));

  free(ratings);

  return 0;
}
