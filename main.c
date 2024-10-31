#include <stdio.h>
#include "themes.h"
#include "genres.h"
#include "sadness.h"

struct Movie {
  char title[70];
  Sadness sadness;
  Themes themes[5];
  Genres genres[5];
};


int main() {
  printf("Lavet af: Elias, Isabella, Kevin, Mathias, Matilde, Oliver, Tobias ");

  return 0;
}