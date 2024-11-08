#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ratings.h"

int userProfilesWrite(Ratings *rate10Movies){
  FILE *fp1;
  fp1 = fopen("users.csv", "a+");
  char line[100];
  char user[30];

  if (fp1 == NULL){
    printf("Error opening file.\n");
    return 1;
  }
  printf("Enter your username: ");
  scanf("%s", user);
  fprintf(fp1, "%s, ", user);
  for (int i = 0; i < 10; i++){
    fprintf(fp1, "%d, ", rate10Movies[i].rating);
  }
  fprintf(fp1, "\n");

  fclose(fp1);

  return 0;
}
