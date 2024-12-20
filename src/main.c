#include "accountCheck.h"
#include "dataLoad.h"
#include "genres.h"
#include "movie.h"
#include "ratings.h"
#include "sadness.h"
#include "scoreMovies.h"
#include "search.h"
#include "themes.h"
#include "userProfiles.h"
#include "userSearch.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Ratings ratings[10] = {
      {"'The Shawshank Redemption' (1994) by Frank Darabont", 0},
      {"'The Dark Knight' (2008) by Christopher Nolan", 0},
      {"'The Wolf of Wall Street' (2013) by Martin Scorsese", 0},
      {"'Coco' (2017) by Adrian Molina", 0},
      {"'Back to the Future' (1985) by Robert Zemeckis", 0},
      {"'Gladiator' (2000) by Ridley Scott", 0},
      {"'Casablanca' (1942) by Michael Curtiz", 0},
      {"'WALL-E' (2008) by Andrew Stanton", 0},
      {"'Fight Club' (1999) by David Fincher", 0},
      {"'Modern Times' (1936) by Charlie Chaplin", 0}};
  Movie movies[250];
  dataLoad(movies);

  int userCheck = accountCheck();
  if (userCheck == 1) {
    rate10Movies(ratings);
    userProfilesWrite(ratings);
  } else if (userCheck == 0) {
    char user;
    scanf("%s", &user);
    int j = userSearch(&user);
    int userArray[10];
    int size = 0;
    stringToIntArray(userProfiles[j].userRatings, userArray, &size);

    for (int i = 0; i < 10; i++) {
      ratings[i].rating = userArray[i];
    }

  } else {
    printf("Invalid input\n");
  }
  int searchedGenreIndex[250] = {0};

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
  insertionSort(movies, 250);
  int matchCount = 0;

  if (genre != NO_GENRE) {
    matchCount =
        searchGenre(movies, 250, getGenreName(genre), searchedGenreIndex);
  } else {
    matchCount = 250;
    for (int i = 0; i < 250; i++) {
      searchedGenreIndex[i] = i;
    }
  }

  int filteredMovieIndexes[250] = {0};
  int filteredMovieCount = filterMoviesBySadness(
      movies, searchedGenreIndex, matchCount, mood, filteredMovieIndexes);

  recommendMovies(movies, filteredMovieIndexes, filteredMovieCount);

  return 0;
}
