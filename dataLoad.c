#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "movie.h"
#define MAXCHAR 500

int dataLoad(Movie *movie) {
    FILE *fp; // Initializing file pointer
    fp = fopen("IMDBTop250Movies.csv", "r"); // r - read mode
    if (fp == NULL) { 
        printf("Error opening file.\n");
        return 1;
    }
 // Åbner for 250 tomme "pladser" i structuren movieVariables
    int counter = 0; // Bruges som en counter til hver linje gennemgået.
    char line[MAXCHAR]; // Et array med MAXCHAR pladser.
    
    fgets(line, MAXCHAR, fp);
 
    while (fgets(line, MAXCHAR, fp) != NULL && counter < 250) {
          // While loop som anvender funktionen fgets. Den skal bruge et sted at opbevare dataen, maks antal characters den skal læse, og fra hvilken fil. Hvis det lykkedes opbevares dataen i det første parameter. Stopper hvis filen er tom, og derfor er NULL.
        if (sscanf(line, "%d; %100[^;]; %d; %100[^;]; %100[^\n]", 
                   &movie[counter].rank, movie[counter].title, 
                   &movie[counter].sadness, movie[counter].theme, 
                   movie[counter].genre) != 5) {
            printf("Error parsing line: %s\n", line);
            continue;
        }
        movie[counter].points = 0;
        counter++;
    }
    fclose(fp);
    return 0;
}