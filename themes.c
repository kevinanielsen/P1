#include <stdio.h>
#include "themes.h"

void getTheme (Themes *theme); 
const char* getThemeName(Themes theme);

void getTheme(Themes *theme) {
    printf("\nHvilket tema vil du se?\n");

    for (int i = IDENTITY; i <= REVENGE; i++) {
     printf(" %d: %s\n", i, getThemeName(i));
    }
    
    printf("\nTast et tal mellem 0-24\n");
    int input;
    scanf(" %d", &input);

    if (input >= IDENTITY && input <= REVENGE) {
        *theme = (Themes) input;
    } else {
        printf("Ugyldigt temavalg\n");
        *theme = IDENTITY;
    } 
}

const char* getThemeName(Themes theme) {
    switch (theme) {
        case IDENTITY: 
            return "Identity";
        case FRIENDSHIP: 
            return "Friendship";
        case COURAGE: 
            return "Courage";
        case FEAR: 
            return "Fear";
        case SACRIFICE: 
            return "Sacrifice";
        case POWER_AND_CORRUPTION: 
            return "Power and Corruption";
        case BETRAYAL: 
            return "Betrayal";
        case GOOD_VS_EVIL: 
            return "Good vs. Evil";
        case ADVENTURE: 
            return "Adventure";
        case JUSTICE: 
            return "Justice";
        case SURVIVAL: 
            return "Survival";
        case LOVE: 
            return "Love";
        case WAR_AND_PEACE: 
            return "War and Peace";
        case FAMILY: 
            return "Family";
        case DREAMS_AND_ASPIRATIONS: 
            return "Dreams and Aspirations";
        case COMING_OF_AGE: 
            return "Coming of Age";
        case LOSS: 
            return "Loss";
        case FREEDOM: 
            return "Freedom";
        case HOPE: 
            return "Hope";
        case REDEMPTION: 
            return "Redemption";
        case MENTAL_HEALTH: 
            return "Mental Health";
        case TECHNOLOGY_AND_HUMANITY: 
            return "Technology and Humanity";
        case COMEDY: 
            return "Comedy";
        case REVENGE: 
            return "Revenge";
        default: 
            return "Unknown";
    }
}