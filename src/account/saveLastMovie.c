#include <stdio.h>
#include <stdlib.h>
#include "movie.h"

int saveLastMovie(const char *recommendedMovie, char *user) {
    FILE *fp4;
    fp4 = fopen("userMovieReviews.csv", "a+");
    
    if (fp4 == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    fprintf(fp4, "%s , %s\n", user, recommendedMovie);
    fclose(fp4);

    return 0;
}

