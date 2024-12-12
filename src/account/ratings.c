#include "ratings.h"
#include <stdio.h>
#include <stdlib.h>

Ratings *rate10Movies(Ratings *ratings) {
    printf("Help us recommend your next favorite movie! Just rate these 10 movies to get started!\n");
    printf("Please rate each movie from 1 to 5 stars based on your personal opinion.\n");
    printf("If you have not watched the movie, please type 0:\n");

  for (int i = 0; i < 10; i++) {
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
  return ratings;
}
