#include <stdio.h>
#include <stdlib.h>
#include "genres.h"
#include "dataLoad.h"
#include "ratings.h"
#include "sadness.h"

int main() {
  dataLoad();
  
  printf("Made by: Elias, Isabella, Kevin, Mathias, Matilde, Oliver, Tobias \n");

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
  


