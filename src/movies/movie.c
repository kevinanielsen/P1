#include <stdio.h>
#include <stdlib.h>
#include "movie.h"
#include "search.h"
#include "saveLastMovie.h"

void insertionSort(Movie movie[], int n) {
  for (int i = 1; i < n; ++i) {
    Movie key = movie[i];
    int j = i - 1;

    while (j >= 0 && movie[j].points < key.points) {
      movie[j + 1] = movie[j];
      j = j - 1;
    }
    movie[j + 1] = key;
  }
}

void recommendMovies(Movie *movies, int *searchedGenreIndex, int matchCount, char *user) {
  if (matchCount <= 0) {
    printf("Invalid input data.\n");
    return;
  }

  for (int i = 0; i < matchCount; i++) {
    int answer;
    Movie recommendedMovie = movies[searchedGenreIndex[i]];

    printf("Our recommendation is: %s \nIncluding genres: %s\n",
           recommendedMovie.title, recommendedMovie.genre);

    while (1) {
      printf("Do you want to watch this movie? (1 = yes, 0 = no)\n");
      int isInputNumber = scanf(" %d", &answer);

      if (!isInputNumber) {
        while (getchar() != '\n')
          ;
        printf("Invalid input. Please enter 1 for yes or 0 for no.\n");
        continue;
      }

      if (answer == 1) {
        printf("Enjoy your movie: %s!\n", recommendedMovie.title);
        saveLastMovie(recommendedMovie.title, user);
        return;
      } else if (answer == 0) {
        break;
      } else {
        printf("Invalid choice. Please enter 1 for yes or 0 for no.\n");
      }
    }
  }

  printf("No more recommendations available.\n");
}
