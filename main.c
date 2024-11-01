#include <stdio.h>
#include "themes.h"
#include "genres.h"
#include "dataLoad.h"
#include "sadness.h"

void get_mood (int *mood);

int main() {
  dataLoad();
  
  printf("Lavet af: Elias, Isabella, Kevin, Mathias, Matilde, Oliver, Tobias \n");

  int mood;
  get_mood(&mood);
  printf("Mood: %d", mood);

  Genres genre;
  getGenre(&genre);
  printf("Genre: %s\n", getGenreName(genre));
  
  Themes theme;
  get_theme(&theme);
  printf("Theme: %s\n", get_theme_name(theme));

  return 0;
  
}

void get_mood (int *mood){
    printf("Hvilket mood er du i?\n");
    printf("Tast 1, 2, 3 eller 4\n");
    printf("1 No sadness, 2 Mild sadness, 3 Moderate sadness og 4 Severe sadness\n");
    scanf(" %d", mood );

    return; 
}
