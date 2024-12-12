#ifndef userSearch_H
#define userSearch_H
#include "themes.h"
#include "genres.h"

typedef struct userProfiles {
  char user[500];
  char userRatings[500];

} userProfile;

userProfile userProfiles[250];

int userSearch(char *user);
int stringToIntArray(char *str, int *array, int *size);
#endif 
