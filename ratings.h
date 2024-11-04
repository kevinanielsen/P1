#ifndef ratings_H
#define ratings_H
#include "themes.h"

typedef struct Ratings{
    const char *title; 
    int rating;        
} Ratings;

typedef struct RatedTheme {
  Themes theme;
  int Points;
} RatedTheme;

RatedTheme RatedThemes[25];

// Function prototypes, macros, etc.
Ratings *rate10Movies();

#endif //ratings_H
