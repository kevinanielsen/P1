#include "dataLoad.h"
#include "genres.h"
#include "movie.h"
#include "ratings.h"
#include "sadness.h"
#include "search.h"
#include "accountCheck.h"
#include "userProfiles.h"
#include "userSearch.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

  Movie movies[250];
  dataLoad(movies);
  int searchedGenreIndex[250];
  searchGenre(movies, 250, "Action", searchedGenreIndex);
  // searchTheme(movie, 250, "Fear");

  int check;
  check = accountCheck();
  if(check == 1){
    Ratings *ratings = malloc(10 * sizeof(Ratings));
    ratings = rate10Movies();
    userProfilesWrite(ratings);

    Sadness mood;
    getMood(&mood);

    Genres genre;
    getGenre(&genre);
    printf("Genre: %s\n", getGenreName(genre));

    recommendMovies(movies);

    free(ratings);
  }
  else if(check == 0){
    char user;
    printf("Enter your username and choose a Genre. \n");
    scanf("%s", &user);
  
    int j = userSearch(&user);
    int array[9];
    int size = 0;
    stringToIntArray(userProfiles[j].userRatings, array, &size);
   
    // Hvor skal arrayet indsættes til anbefalingen af film?

    Sadness mood;
    getMood(&mood);

    Genres genre;
    getGenre(&genre);
    printf("Genre: %s\n", getGenreName(genre));

    recommendMovies(movies);

    // Udleverer ny film herefter.
  }
  else{
    printf("Invalid input\n");
  }
  return 0;
}