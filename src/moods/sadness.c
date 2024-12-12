#include "sadness.h"
#include <stdio.h>

const char *getMoodName(int mood) {
  switch (mood) {
  case NO_SADNESS:
    return "No sadness";
  case MILD_SADNESS:
    return "Mild sadness";
  case MODERATE_SADNESS:
    return "Moderate sadness";
  case SEVERE_SADNESS:
    return "Severe sadness";
  default:
    return "Unknown mood";
  }
}

void getMood(Sadness *mood) {
  printf("Please state your current mood, with a focus on any feelings of "
         "sadness you may be experiencing!\n");
  printf("Press 0 - 3\n");

  for (int i = NO_SADNESS; i <= SEVERE_SADNESS; i++) {
    printf(" %d: %s\n", i, getMoodName(i));
  }
  
  int input;
  while (1) {
    printf("\nEnter a number between 0-3\n");
    scanf(" %d", &input);
      if (input >= NO_SADNESS && input <= SEVERE_SADNESS) {
        *mood = (Sadness)input;
        break;
      } else {
        printf("Invalid input! Please enter a number between 0 and 3.\n");
      }
  }
}