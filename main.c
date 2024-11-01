#include <stdio.h>
#include "themes.h"
#include "genres.h"
#include "dataLoad.h"
#include "sadness.h"

void get_mood (Sadness *mood);
void get_genre (Genres *genre); 
void get_theme (Themes *theme); 
const char* get_genre_name(Genres genre);
const char* get_theme_name(Themes theme);
const char* get_mood_name(Sadness mood);


int main() {
  dataLoad();
  
  printf("Made by: Elias, Isabella, Kevin, Mathias, Matilde, Oliver, Tobias \n");

  Sadness mood;
  get_mood(&mood);
  printf("Mood: %s\n", get_mood_name(mood));
  
  Genres genre;
  get_genre(&genre);
  printf("Genre: %s\n", get_genre_name(genre));

  Themes theme;
  get_theme(&theme);
  printf("Theme: %s\n", get_theme_name(theme));
  
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


void get_genre (Genres *genre) {
    printf("\nWhat genre do you want to see?\n");

    for (int i = ACTION; i <= RETRO; i++) {
        printf(" %d: %s\n", i, get_genre_name(i));
    }
    
    printf("\nEnter a number between 0-21\n");
    int input;
    scanf(" %d", &input);

    if (input >= ACTION && input <= RETRO) {
        *genre = (Genres) input;
    } else {
        printf("Invalid input\n");
        *genre = ACTION;
    } 
}

void get_theme(Themes *theme) {
    printf("\nHvilket tema vil du se?\n");

    for (int i = IDENTITY; i <= REVENGE; i++) {
     printf(" %d: %s\n", i, get_theme_name(i));
    }
    
    printf("\nEnter a number between 0-23\n");
    int input;
    scanf(" %d", &input);

    if (input >= IDENTITY && input <= REVENGE) {
        *theme = (Themes) input;
    } else {
        printf("Invalid input\n");
        *theme = IDENTITY;
    } 
}
const char* get_mood_name(Sadness mood){
  switch (mood){
    case NO_SADNESS:
        return "NO_SADNESS";
   case MILD_SADNESS:
        return "MILD_SADNESS";
   case MODERATE_SADNESS:
       return "MODERATE_SADNESS";
   case SEVERE_SADNESS:
        return "SEVERE_SADNESS";
    default: 
        return "Unknown";
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
