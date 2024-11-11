#include "themes.h"
#include "movie.h"
#include "ratings.h"
#include "search.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getTheme(Themes *theme) {
  printf("\nHvilket tema vil du se?\n");

  for (int i = IDENTITY; i <= REVENGE; i++) {
    printf(" %d: %s\n", i, getThemeName(i));
  }

  printf("\nTast et tal mellem 0-24\n");
  int input;
  scanf(" %d", &input);

  if (input >= IDENTITY && input <= REVENGE) {
    *theme = (Themes)input;
  } else {
    printf("Ugyldigt temavalg\n");
    *theme = IDENTITY;
  }
}

const char *themeNames[] = {"Identity",
                            "Friendship",
                            "Courage",
                            "Fear",
                            "Sacrifice",
                            "Power and Corruption",
                            "Betrayal",
                            "Good vs. Evil",
                            "Adventure",
                            "Justice",
                            "Survival",
                            "Love",
                            "Isolation",
                            "War and Peace",
                            "Family",
                            "Dreams and Aspirations",
                            "Coming of Age",
                            "Loss",
                            "Freedom",
                            "Hope",
                            "Redemption",
                            "Mental Health",
                            "Technology and Humanity",
                            "Comedy",
                            "Revenge"};

const char *getThemeName(Themes theme) {
  if (theme >= 0 && theme < sizeof(themeNames) / sizeof(themeNames[0])) {
    return themeNames[theme];
  } else {
    return "Unknown";
  }
}

Themes getThemeEnum(const char *themeName) {
  for (int i = 0; i < sizeof(themeNames) / sizeof(themeNames[0]); i++) {
    if (strcasecmp(themeNames[i], themeName) ==
        0) { // Use case-insensitive comparison
      return (Themes)i;
    }
  }
  return -1;
}

Themes *processThemes(const char *input) {
  char str[256];
  strncpy(str, input, sizeof(str) - 1);
  str[sizeof(str) - 1] = '\0';

  Themes *themes = malloc((5 + 1) * sizeof(Themes));
  if (!themes)
    return NULL;

  int themeCount = 0;

  char *token = strtok(str, ",");
  while (token != NULL && themeCount < 5) {
    while (*token == ' ')
      token++;
    char *end = token + strlen(token) - 1;
    while (end > token && *end == ' ') {
      *end = '\0';
      end--;
    }

    Themes theme = getThemeEnum(token);
    if (theme != -1) {
      themes[themeCount++] = theme;
    }
    token = strtok(NULL, ",");
  }
  themes[themeCount] = -1; // Null-terminate the array

  return themes;
}

int searchRatedThemes(Themes searchTheme, RatedTheme *ratedThemes) {
  for (int i = 0; i < 25; i++) {
    if (ratedThemes[i].theme == searchTheme) {
      return i;
    }
  }
  return -1;
}

void scoreThemes(Movie *movies, RatedTheme *ratedThemes, Ratings *ratings) {
  for (int i = 0; i < 25; i++) {
    ratedThemes[i].theme = i;
    ratedThemes[i].rating = 0;
  }

  for (int i = 0; i < 10; i++) {
    int movieIndex = getMovieByTitle(movies, 250, ratings[i].title);
    if (movieIndex == -1) {
      printf("Warning: Movie not found: %s\n", ratings[i].title);
      continue;
    }

    Themes *themes = processThemes(movies[movieIndex].theme);
    if (!themes) {
      printf("Warning: Failed to process themes for movie: %s\n",
             movies[movieIndex].title);
      continue;
    }

    for (int j = 0; themes[j] != -1 && j < 5; j++) {
      Themes currentTheme = themes[j];
      if (currentTheme >= 0 && currentTheme < 25) {
        ratedThemes[currentTheme].rating += ratings[i].rating;
      }
    }
    free(themes);
  }
}