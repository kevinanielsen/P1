#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "movie.h"
#define MAXCHAR 500

Movie *dataLoad(void) {
    FILE *fp; // Initializing file pointer
    fp = fopen("IMDBTop250Movies.csv", "r"); // r - read mode
    if (fp == NULL) { 
        printf("Error opening file.\n");
        return NULL;
    }
    Movie* movies = (Movie*)malloc(250 * sizeof(Movie));
    int counter = 0; // Bruges som en counter til hver linje gennemgået.
    char line[MAXCHAR]; // Et array med MAXCHAR pladser.
    
    fgets(line, MAXCHAR, fp);

    while (fgets(line, MAXCHAR, fp) != NULL && counter < 250) {
          // While loop som anvender funktionen fgets. Den skal bruge et sted at opbevare dataen, maks antal characters den skal læse, og fra hvilken fil. Hvis det lykkedes opbevares dataen i det første parameter. Stopper hvis filen er tom, og derfor er NULL.
        if (sscanf(line, "%d; %100[^;]; %d; %100[^;]; %100[^\n]", 
                   &movies[counter].rank, movies[counter].title, 
                   &movies[counter].sadness, movies[counter].theme, 
                   movies[counter].genre) != 5) {
            printf("Error parsing line: %s\n", line);
            continue;
        }
        counter++;
    }
    fclose(fp);

    for (int i = 0; i < 251; i++) {
        char genres[5] = {};
        sscanf(movies[i].genre, "%100[^,]", &genres[0]);
        for (int j = 0; j < 5; j++) {
            if (genres[j] == '\0') {
                break;
            }
            printf("Genre: %s\n", genres[j]);
        }
    }

    return movies;
}