#include <stdio.h>

typedef struct Ratings{
    const char *title; 
    int rating;        
} Ratings;

void rate_10_movies()
{
 
    Ratings ratings[10] = {
        {"'The Shawshank Redemption' (1994) by Frank Darabont", 0},
        {"'The Dark Knight' (2008) by Christopher Nolan", 0},
        {"'The Wolf of Wall Street' (2013) by Martin Scorsese", 0},
        {"'Coco' (2017) by Adrian Molina", 0},
        {"'Back To The Future' (1985) by Robert Zemeckis", 0},
        {"'Gladiator' (2000) by Ridley Scott", 0},
        {"'Casablanca' (1942) by Michael Curtiz", 0},
        {"'WALL-E' (2008) by Andrew Stanton", 0},
        {"'Fight Club' (1999) by David Fincher", 0},
        {"'Modern Times' (1936) by Charlie Chaplin", 0}
    };

    printf("Help us recommend your next favorite movie! Just rate these 10 movies to get started!\n");
    printf("Please rate each movie from 1 to 5 stars based on your personal opinion.\n");
    printf("If you have not watched the movie, please type 0:\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%s\n", ratings[i].title);
        int rating;
        while (1) {
            printf("Your rating: ");
            scanf("%d", &rating);
            if (rating >= 0 && rating <= 5) {
                ratings[i].rating = rating;
                break;
            } else {
                printf("Invalid rating! Please enter a number between 0 and 5.\n");
            }
        }
    }
}