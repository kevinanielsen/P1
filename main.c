#include <stdio.h>
#include "themes.h"
#include "genres.h"
#include "sadness.h"


void get_mood (int *mood);
void get_genre (Genres *genre); 
void get_theme (Themes *theme); 
const char* get_genre_name(Genres genre);
const char* get_theme_name(Themes theme);

struct Movie {
  char title[70];
  Sadness sadness;
  Themes themes[5];
  Genres genres[5];
};


int main() {
  printf("Lavet af: Elias, Isabella, Kevin, Mathias, Matilde, Oliver, Tobias ");

  int mood;
  get_mood(&mood);
  printf("Mood: %d", mood);
  
  Genres genre;
  get_genre(&genre);
  printf("Genre: %s\n", get_genre_name(genre));

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

void get_genre (Genres *genre) {
    printf("\nHvilken genre vil du se?\n");

    for (int i = ACTION; i <= RETRO; i++) {
        printf(" %d: %s\n", i, get_genre_name(i));
    }
    
    printf("\nTast et tal mellem 0-21\n");
    int input;
    scanf(" %d", &input);

    if (input >= ACTION && input <= RETRO) {
        *genre = (Genres) input;
    } else {
        printf("Ugyldigt genrevalg\n");
        *genre = ACTION;
    } 
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

const char* get_genre_name(Genres genre) {
    switch (genre) {
        case ACTION: 
            return "ACTION";
        case ADVENTURE_GENRE: 
            return "ADVENTURE";
        case ANIMATION: 
         return "ANIMATION";
        case BIOGRAPHY: 
         return "BIOGRAPHY";
        case COMEDY_GENRE: 
         return "COMEDY"; 
        case CRIME: 
         return "CRIME";
        case DRAMA: 
         return "DRAMA";
        case FAMILY_GENRE: 
          return "FAMILY";
        case FANTASY: 
            return "FANTASY";
        case FILM_NOIR: 
            return "FILM_NOIR";
        case HISTORY: 
            return "HISTORY";
        case HORROR: 
            return "HORROR";
        case MUSIC: 
            return "MUSIC";
        case MUSICAL: 
            return "MUSICAL";
        case MYSTERY: 
            return "MYSTERY";
        case ROMANCE: 
            return "ROMANCE";
        case SCI_FI: 
            return "SCI_FI";
        case SPORT: 
            return "SPORT";
        case THRILLER: 
            return "THRILLER";
        case WAR: 
            return "WAR";
        case WESTERN: 
            return "WESTERN";
        case RETRO: 
            return "RETRO";
        default: 
            return "Unknown";
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
