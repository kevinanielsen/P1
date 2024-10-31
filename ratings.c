
#include <stdio.h>

int rate_10_movies () {
    int stars;

    printf("Help us recommend your next favourite movie! Just rate these 10 movies to get started!\n");
    printf("Please rate each movie from 1 to 5 stars based on your personal opinion.\n");
    printf("If you have not watched the movie, please type 0:\n");
    
    printf("'The Shawshank Redemption'(1994) by Frank Darabont\n");
    printf("Your rating: \n");
    scanf(" %d", &stars);

    printf("'The Dark Knight'(2008) by Christopher Nolan\n");
    printf("Your rating: \n");
    scanf(" %d", &stars);

    printf("'The Wolf of Wall Street'(2013) by Martin Scorsese\n");
    printf("Your rating: \n");
    scanf(" %d", &stars);

    printf("'Coco'(2017) by Adrian Molina\n");
    printf("Your rating: \n");
    scanf(" %d", &stars);

    printf("'Back To The Future'(1985) by Robert Zemeckis\n");
    printf("Your rating: \n");
    scanf(" %d", &stars);
    
    printf("'Gladiator'(2000) by Ridley Scott\n");
    printf("Your rating: \n");
    scanf(" %d", &stars);
    
    printf("'Casablanca'(1942) by Michael Curtiz\n");
    printf("Your rating: \n");
    scanf(" %d", &stars);
    
    printf("'WALL-E'(2008) by Andrew Stanton\n");
    printf("Your rating: \n");
    scanf(" %d", &stars);
    
    printf("'Fight Club'(1999) by David Fincher\n");
    printf("Your rating: \n");
    scanf(" %d", &stars);
    
    printf("'Modern Times'(1936) by Charlie Chaplin\n");
    printf("Your rating: \n");
    scanf(" %d", &stars);

    return 0;
}
