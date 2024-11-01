#include <stdio.h>
#include "themes.h"
#include "genres.h"
#include "dataLoad.h"
#include "sadness.h"

void get_mood (int *mood);
void get_theme (Themes *theme); 
const char* get_theme_name(Themes theme);

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


void get_theme(Themes *theme) {
    printf("\nHvilket tema vil du se?\n");

    for (int i = IDENTITY; i <= REVENGE; i++) {
     printf(" %d: %s\n", i, get_theme_name(i));
    }
    
    printf("\nTast et tal mellem 0-23\n");
    int input;
    scanf(" %d", &input);

    if (input >= IDENTITY && input <= REVENGE) {
        *theme = (Themes) input;
    } else {
        printf("Ugyldigt genrevalg\n");
        *theme = IDENTITY;
    } 
}


const char* get_theme_name(Themes theme) {
    switch (theme) {
        case IDENTITY: 
            return "IDENTITY";
        case FRIENDSHIP: 
            return "FRIENDSHIP";
        case COURAGE: 
            return "COURAGE";
        case FEAR: 
            return "FEAR";
        case SACRIFICE: 
            return "SACRIFICE";
        case POWER_AND_CORRUPTION: 
            return "POWER_AND_CORRUPTION";
        case BETRAYAL: 
            return "BETRAYAL";
        case GOOD_VS_EVIL: 
            return "GOOD_VS_EVIL";
        case ADVENTURE: 
            return "ADVENTURE";
        case JUSTICE: 
            return "JUSTICE";
        case SURVIVAL: 
            return "SURVIVAL";
        case LOVE: 
            return "LOVE";
        case WAR_AND_PEACE: 
            return "WAR_AND_PEACE";
        case FAMILY: 
            return "FAMILY";
        case DREAMS_AND_ASPIRATIONS: 
            return "DREAMS_AND_ASPIRATIONS";
        case COMING_OF_AGE: 
            return "COMING_OF_AGE";
        case LOSS: 
            return "LOSS";
        case FREEDOM: 
            return "FREEDOM";
        case HOPE: 
            return "HOPE";
        case REDEMPTION: 
            return "REDEMPTION";
        case MENTAL_HEALTH: 
            return "MENTAL_HEALTH";
        case TECHNOLOGY_AND_HUMANITY: 
            return "TECHNOLOGY_AND_HUMANITY";
        case COMEDY: 
            return "COMEDY";
        case REVENGE: 
            return "REVENGE";
        default: 
            return "Unknown";
    }
}
