#include "dataLoad.h"
#include "genres.h"
#include "movie.h"
#include "ratings.h"
#include "sadness.h"
#include "search.h"
#include "accountCheck.h"
#include "userProfiles.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int check;

  Movie movie[250];
  dataLoad(movie);
  int searchedGenreIndex[250];
  searchGenre(movie, 250, "Action", searchedGenreIndex);
  // searchTheme(movie, 250, "Fear");


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

    free(ratings);
  }
  else if(check == 0){
    printf("Enter your username and choose a Genre. \n");
    // Funktion som søger efter brugerens data i csv filen. Derefter skal brugerens data indlæses og bruges til at anbefale en film om igen.

     
    Sadness mood;
    getMood(&mood);

    Genres genre;
    getGenre(&genre);
    printf("Genre: %s\n", getGenreName(genre));

    // Udleverer ny film herefter.
  }
  else{
    printf("Invalid input\n");
  }



  return 0;
}
