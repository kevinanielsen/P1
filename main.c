#include <stdio.h>
#include "themes.h"
#include "genres.h"
#include "dataLoad.h"
#include "sadness.h"

int main() {
  dataLoad();
  
  printf("Made by: Elias, Isabella, Kevin, Mathias, Matilde, Oliver, Tobias \n");

  Sadness mood;
  get_mood(&mood);

  Genres genre;
  getGenre(&genre);
  printf("Genre: %s\n", getGenreName(genre));
  
  Themes theme;
  getTheme(&theme);
  printf("Theme: %s\n", getThemeName(theme));

  return 0;
}
  

void get_mood (Sadness *mood){
    printf("What mood are you in??\n");
    printf("Press 0, 1, 2 or 3\n");
    printf("0 No sadness, 1 Mild sadness, 2 Moderate sadness og 3 Severe sadness\n");
 
    for (int i = NO_SADNESS; i <= SEVERE_SADNESS; i++) {
        printf(" %d: %s\n", i, get_mood_name(i));
    }
    
    printf("\nEnter a number between 0-3\n");
    int input;
    scanf(" %d", &input);

    if (input >= NO_SADNESS && input <= SEVERE_SADNESS) {
        *mood = (Sadness) input;
    } else {
        printf("Invalid input\n");
        *mood = NO_SADNESS;
    } 
}
