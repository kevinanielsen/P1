#include "sadness.h"
#include <stdio.h> 

const char *getMoodName(int mood){
    switch (mood) {
        case NO_SADNESS: return "No sadness";
        case MILD_SADNESS: return "Mild sadness";
        case MODERATE_SADNESS: return "Moderate sadness";
        case SEVERE_SADNESS: return "Severe sadness";
        default: return "Unknown mood";
    }
}

void getMood (Sadness *mood){
    printf("What mood are you in??\n");
    printf("Press 0, 1, 2 or 3\n");
    printf("0 No sadness, 1 Mild sadness, 2 Moderate sadness og 3 Severe sadness\n");
 
    for (int i = NO_SADNESS; i <= SEVERE_SADNESS; i++) {
        printf(" %d: %s\n", i, getMoodName(i));
    }
    
    printf("\nEnter a number between 0-3\n");
    int input;
    scanf(" %d", &input);

    if (input >= NO_SADNESS && input <= SEVERE_SADNESS) {
        *mood = (Sadness) input;
    } else {
        printf("Invalid input\n");
        *mood = NO_SADNESS;
    } 
}