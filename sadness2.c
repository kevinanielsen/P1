#include <stdio.h>
#include <string.h>
#include "movie.h"
#include "sadness.h"

void getMood(Sadness *mood) {
    int userMood;
    
    printf("How do you feel today?\n");
    printf("0 - No sadness\n");
    printf("1 - Mild sadness\n");
    printf("2 - Sadness\n");
    printf("3 - Severe sadness\n");
    
    scanf("%d", &userMood);
    
    if (userMood >= 0 && userMood <= 3) {
        *mood = (Sadness)userMood;
    } else {
        printf("Invalid mood. Please enter a number between 0 and 3.\n");
        getMood(mood);  
    }
}

void recommendMovies(Movie *movies, int movieCount, Sadness mood) {
    printf("\nRecommended Movies based on your mood (Mood: %s):\n", getMoodName(mood));

    for (int i = 0; i < movieCount; i++) {
       
        if (mood == NO_SADNESS && movies[i].sadness == NO_SADNESS) {
            printf("- %s\n", movies[i].title);
        } 
        else if (mood == MILD_SADNESS && movies[i].sadness != SEVERE_SADNESS) {
            printf("- %s\n", movies[i].title);
        } 
        else if (mood == MODERATE_SADNESS && movies[i].sadness != SEVERE_SADNESS && movies[i].sadness) {
            printf("- %s\n", movies[i].title);
        } 
        else if (mood == SEVERE_SADNESS && movies[i].sadness == NO_SADNESS) {
            printf("- %s\n", movies[i].title);
        }
    }
}

const char *getMoodName(int mood) {
    switch (mood) {
        case NO_SADNESS: return "No sadness";
        case MILD_SADNESS: return "Mild sadness";
        case MODERATE_SADNESS: return "Sadness";
        case SEVERE_SADNESS: return "Severe sadness";
        default: return "Unknown mood";
    }
}

void filterMovies(Movie *movies, int movieCount, Sadness mood) {
    printf("\nMovies available based on your mood (Mood: %s):\n", getMoodName(mood));
    
    for (int i = 0; i < movieCount; i++) {
        if (mood == NO_SADNESS) {
            // Alle film tillades
            printf("- %s\n", movies[i].title);
        } 
        else if (mood == MILD_SADNESS && movies[i].sadness <= MILD_SADNESS) {
            // Ingen "Severe sadness" film
            printf("- %s\n", movies[i].title);
        } 
        else if (mood == MODERATE_SADNESS && movies[i].sadness == MODERATE_SADNESS) {
            // Kun "Moderate sadness"-film tilladt
            printf("- %s\n", movies[i].title);
        } 
        else if (mood == SEVERE_SADNESS && movies[i].sadness >= MODERATE_SADNESS) {
            // Kun "Sadness" eller højere tillades
            printf("- %s\n", movies[i].title);
        }
    }
}