#ifndef THEMES_H
#define THEMES_H

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

void getTheme (Themes *theme); 
const char* getThemeName(Themes theme);

#endif