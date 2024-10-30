#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXCHAR 500

enum {kTitle = 100, kGenre = 100, kThemes = 100};
typedef struct {
    int rank;
    char title[kTitle];
    int sadness;
    char genre[kGenre];
    char theme[kThemes];
} movieVariables;

int main(void) {
    FILE *fp; // Initializing file pointer

    fp = fopen("IMDBTop250Movies.csv", "r"); // r - read mode
    if (fp == NULL) { 
        printf("Error opening file.\n");
        return 1;
    }

    movieVariables variable[250]; // Åbner for 250 tomme "pladser" i structuren movieVariables
    int counter = 0; // Bruges som en counter til hver linje gennemgået.
    char line[MAXCHAR]; // Et array med MAXCHAR pladser.
    
    while (fgets(line, MAXCHAR, fp) != NULL && counter < 251) {  // While loop som anvender funktionen fgets. Den skal bruge et sted at opbevare dataen, maks antal characters den skal læse, og fra hvilken fil. Hvis det lykkedes opbevares dataen i det første parameter. Stopper hvis filen er tom, og derfor er NULL.
        sscanf(line, "%d; %69[^;]; %d; %69[^;]; %69[^\n]", 
        &variable[counter].rank, variable[counter].title, 
        &variable[counter].sadness, variable[counter].genre, 
        variable[counter].theme);
        // De indsatte værdier er det maksimale antal characters. Hvert placeholder stemmer overens med CSV filens rækkefølge.

        counter++;
    }
    fclose(fp);
    
    return 0;
}
