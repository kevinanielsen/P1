#include <stdio.h>
#include "themes.h"
#include "genres.h"
#include "dataLoad.h"
#include "sadness.h"

int main() {
  dataLoad();
  
  printf("Made by: Elias, Isabella, Kevin, Mathias, Matilde, Oliver, Tobias \n");

  Sadness mood;
  getMood(&mood);

  Genres genre;
  getGenre(&genre);
  printf("Genre: %s\n", getGenreName(genre));

  return 0;
}
  


