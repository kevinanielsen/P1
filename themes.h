#ifndef THEMES_H
#define THEMES_H

#include "movie.h"
#include "ratings.h"

typedef enum Themes {
  IDENTITY,
  FRIENDSHIP,
  COURAGE,
  FEAR,
  SACRIFICE,
  POWER_AND_CORRUPTION,
  BETRAYAL,
  GOOD_VS_EVIL,
  ADVENTURE,
  JUSTICE,
  SURVIVAL,
  LOVE,
  ISOLATION,
  WAR_AND_PEACE,
  FAMILY,
  DREAMS_AND_ASPIRATIONS,
  COMING_OF_AGE,
  LOSS,
  FREEDOM,
  HOPE,
  REDEMPTION,
  MENTAL_HEALTH,
  TECHNOLOGY_AND_HUMANITY,
  COMEDY,
  REVENGE,
} Themes;

typedef struct RatedTheme {
  Themes theme;
  int rating;
} RatedTheme;

const char *getThemeName(Themes theme);
void scoreThemes(Movie *movies, RatedTheme *ratedThemes, Ratings *ratings);
Themes *processThemes(const char *input);

#endif
