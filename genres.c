#include "genres.h"
#include <stdio.h>
#include <stdlib.h>

void getGenre(Genres *genre) {
  printf("\nWhat genre would you want to watch?\n");

  for (int i = ACTION; i <= NO_GENRE; i++) {
    printf(" %d: %s\n", i, getGenreName(i));
  }

  printf("\nPlease press 0-22 to choose your desired genre!\n");
  int input;
  while (1) {
    printf("Your genre: ");
    scanf(" %d", &input);
    if (input >= ACTION && input <= NO_GENRE) {
      *genre = (Genres)input;
      break;
    } else {
      printf("Invalid genre! Please enter a number between 0 and 22.\n");
    }
  }
}

char *getGenreName(Genres genre) {
  switch (genre) {
  case ACTION:
    return "Action";
  case ADVENTURE_GENRE:
    return "Adventure";
  case ANIMATION:
    return "Animation";
  case BIOGRAPHY:
    return "Biography";
  case COMEDY_GENRE:
    return "Comedy";
  case CRIME:
    return "Crime";
  case DRAMA:
    return "Drama";
  case FAMILY_GENRE:
    return "Family";
  case FANTASY:
    return "Fantasy";
  case FILM_NOIR:
    return "Film-Noir";
  case HISTORY:
    return "History";
  case HORROR:
    return "Horror";
  case MUSIC:
    return "Music";
  case MUSICAL:
    return "Musical";
  case MYSTERY:
    return "Mystery";
  case ROMANCE:
    return "Romance";
  case SCI_FI:
    return "Sci-Fi";
  case SPORT:
    return "Sport";
  case THRILLER:
    return "Thriller";
  case WAR:
    return "War";
  case WESTERN:
    return "Western";
  case RETRO:
    return "Retro";
  case NO_GENRE:
    return "No genre";
  default:
    return "Unknown";
  }
}