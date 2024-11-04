#include <stdio.h>
#include "themes.h"
#include "genres.h"
#include "dataLoad.h"
#include "sadness.h"
#include "search.h"
#include "movie.h"

int main() {
  dataLoad();
 
  searchGenre(movie, 250, "Action");

  printf("Pause\n");
  
  searchTheme(movie, 250, "Fear");

  
  printf("Made by: Elias, Isabella, Kevin, Mathias, Matilde, Oliver, Tobias \n");

  Sadness mood;
  getMood(&mood);

  Genres genre;
  getGenre(&genre);
  printf("Genre: %s\n", getGenreName(genre));

  return 0;
}
  


