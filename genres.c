#include "genres.h"
#include <stdio.h>

void getGenre(Genres *genre);
const char *getGenreName(Genres genre);

void getGenre(Genres *genre) {
  printf("\nWhat genre would you want to watch?\n");

  for (int i = ACTION; i <= RETRO; i++) {
    printf(" %d: %s\n", i, getGenreName(i));
  }

  printf("\nPlease press 0-21 to choose your wanted genre!\n");
  int input;
  scanf(" %d", &input);

  if (input >= ACTION && input <= RETRO) {
    *genre = (Genres)input;
  } else {
    printf("Invalid genre\n");
    *genre = ACTION;
  }
}

const char *getGenreName(Genres genre) {
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