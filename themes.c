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
            return "IDENTITY";
        case FRIENDSHIP: 
            return "FRIENDSHIP";
        case COURAGE: 
            return "COURAGE";
        case FEAR: 
            return "FEAR";
        case SACRIFICE: 
            return "SACRIFICE";
        case POWER_AND_CORRUPTION: 
            return "POWER_AND_CORRUPTION";
        case BETRAYAL: 
            return "BETRAYAL";
        case GOOD_VS_EVIL: 
            return "GOOD_VS_EVIL";
        case ADVENTURE: 
            return "ADVENTURE";
        case JUSTICE: 
            return "JUSTICE";
        case SURVIVAL: 
            return "SURVIVAL";
        case LOVE: 
            return "LOVE";
        case WAR_AND_PEACE: 
            return "WAR_AND_PEACE";
        case FAMILY: 
            return "FAMILY";
        case DREAMS_AND_ASPIRATIONS: 
            return "DREAMS_AND_ASPIRATIONS";
        case COMING_OF_AGE: 
            return "COMING_OF_AGE";
        case LOSS: 
            return "LOSS";
        case FREEDOM: 
            return "FREEDOM";
        case HOPE: 
            return "HOPE";
        case REDEMPTION: 
            return "REDEMPTION";
        case MENTAL_HEALTH: 
            return "MENTAL_HEALTH";
        case TECHNOLOGY_AND_HUMANITY: 
            return "TECHNOLOGY_AND_HUMANITY";
        case COMEDY: 
            return "COMEDY";
        case REVENGE: 
            return "REVENGE";
        default: 
            return "Unknown";
    }
}