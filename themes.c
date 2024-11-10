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
    if (strcmp(themeNames[i], themeName) == 0) {
      return (Themes)i;
    }
  }
  return -1;
}

Themes *processThemes(const char *input) {
  // Copy the input string to a mutable array as strtok modifies the string
  char str[256];
  strncpy(str, input, sizeof(str));
  str[sizeof(str) - 1] = '\0'; // Ensure null termination

  Themes *themes = malloc((5 + 1) * sizeof(Themes)); // Allocate space for 6 elements
  int themeCount = 0;

  // Tokenize the string based on ", "
  char *token = strtok(str, ", ");
  while (token != NULL && themeCount < 5) {
    Themes theme;
    theme = getThemeEnum(token);
    if (theme != -1) {
      themes[themeCount] = theme;
      themeCount++;
    }
    token = strtok(NULL, ", ");
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
  int themeCount = 0;
  for (int i = 0; i < 10; i++) {
    int movieIndex = getMovieByTitle(movies, 250, ratings[i].title);

    Themes *themes = processThemes(movies[movieIndex].theme);
    for (int j = 0; j < 5 && themes[j] != -1; j++) {
      int existingIndex = searchRatedThemes(themes[j], ratedThemes);

      if (existingIndex == -1) {  // Theme not found; add new entry
        ratedThemes[themeCount].theme = themes[j];
        ratedThemes[themeCount].rating = ratings[i].rating;
        themeCount++;
      } else {  // Theme found; update existing rating
        ratedThemes[existingIndex].rating += ratings[i].rating;
      }
    }
    free(themes);  // Free allocated memory after use
  }
}

