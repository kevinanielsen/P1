#include <stdio.h>
#include "themes.h"
#include "genres.h"
#include "dataLoad.h"
#include "sadness.h"

void get_mood (int *mood);
void get_genre (Genres *genre); 
const char* get_genre_name(Genres genre);

int main() {
  dataLoad();
  
  printf("Lavet af: Elias, Isabella, Kevin, Mathias, Matilde, Oliver, Tobias \n");

  int mood;
  get_mood(&mood);
  printf("Mood: %d", mood);
  
  Genres genre;
  get_genre(&genre);
  printf("Genre: %s\n", get_genre_name(genre));
  
  Themes theme;
  getTheme(&theme);
  printf("Theme %s\n",getThemeName(theme));

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