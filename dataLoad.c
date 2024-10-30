#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXCHAR 1000

typedef struct {
    char title[70];
    int sadness;
    char genre[70];

} Variables;

int main(void) {
    FILE *fp;
    char row[MAXCHAR];
    Variables variable[250];
    int records = 0;

    fp = fopen("IMDBTop250MoviesNY.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Reading and parsing each row
    while (fgets(row, MAXCHAR, fp) != NULL && records < 250) {
        printf("Row: %s", row);

        // Tokenize by semicolon to extract fields
        char *token = strtok(row, ";");
        int fieldIndex = 0;

        // Temporary variables for parsing
        int id;
        char title[70];
        int sadness;
        char genre[70];

        // Process each token in the row
        while (token != NULL) {
            if (fieldIndex == 0) {
                id = atoi(token);  // Convert the first token to an integer ID
            } else if (fieldIndex == 1) {
                strncpy(title, token, 69);  // Copy the title
                title[69] = '\0';  // Ensure null-termination
            } else if (fieldIndex == 2) {
                sadness = atoi(token);  // Convert the sadness score to an integer
            } else if (fieldIndex == 3){
                strncpy(genre, token, 69);
                genre[69] = '\0'; 
            }
            token = strtok(NULL, ";");
            fieldIndex++;
        }

        // Store the parsed title and sadness in the struct
        strncpy(variable[records].title, title, 69);
        variable[records].title[69] = '\0';  // Ensure null-termination
        variable[records].sadness = sadness;
        strncpy(variable[records].genre, genre, 69);
        variable[records].genre[69] = '\0';

        // Print parsed values
        printf("Parsed title: %s, sadness: %d, Genre: %s\n", variable[records].title, variable[records].sadness, variable[records].genre);

        records++;
    }

    fclose(fp);
    return 0;
}
