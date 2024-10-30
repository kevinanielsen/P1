#include <stdio.h>

void get_mood (int *mood);
void get_genre (int *genre); 

int main (void){

    int mood;
    get_mood(&mood);
    printf("mood: %d", mood);
    
        int genre;
    get_genre(&genre);
    printf("genre: %d", genre);
    return 0;
}

void get_mood (int *mood){

    printf("Hvilket mood er du i?\n");
    printf("Tast 1, 2, 3 eller 4\n");
    printf("1 ikke trist, 2 lidt trist, 3 trist og 4 meget trist\n");
    scanf(" %d", mood );

    return; 
}

void get_genre (int *genre){
    
    char all_genres[22][25]={
    "\n0: ACTION", 
    "\n1: ADVENTURE",
    "\n2: ANIMATION",
    "\n3: BIOGRAPHY",
    "\n4: COMEDY",
    "\n5: CRIME",
    "\n6: DRAMA",
    "\n7: FAMILY",
    "\n8: FANTASY",
    "\n9: FILM_NOIR",
    "\n10: HISTORY",
    "\n11: HORROR",
    "\n12: MUSIC",
    "\n13: MUSICAL",
    "\n14: MYSTERY",
    "\n15: ROMANCE",
    "\n16: SCI_FI",
    "\n17: SPORT",
    "\n18: THRILLER",
    "\n19: WAR",
    "\n20: WESTERN",
    "\n21: RETRO"
    };

    printf("\nHvilket genre vil du se?\n");

    for (int i = 0; i <= 21; i++){
        printf("%s", all_genres[i]);
    }

    printf("\nTast et tal mellem 0-21\n");
    scanf(" %d", genre);
    
    return; 
}