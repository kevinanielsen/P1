#include "movie.h"
#include "search.h"
#include <stdio.h>

void insertionSort(Movie movie[], int n) {
  for (int i = 1; i < n; ++i) {
    Movie key = movie[i];
    int j = i - 1;

    while (j >= 0 && movie[j].points > key.points) {
      movie[j + 1] = movie[j];
      j = j - 1;
    }
    movie[j + 1] = key;
  }
}

void recommendMovies(Movie *movies, int *searchedGenreIndex, int matchCount) {
    int i = 0;
    int running = 1;

    while (running && i < matchCount) {
      int answer;

      Movie recommendedMovie = movies[searchedGenreIndex[i]];

      printf("Our recommendation is: %s \nIncluding genres: %s\n", recommendedMovie.title, recommendedMovie.genre);
      printf("Do you want to watch this movie? (1 = yes, 0 = no)\n");
      scanf(" %d", &answer);

      switch (answer) {
      case 1:
          printf("Enjoy your movie: %s!\n", recommendedMovie.title);
          running = 0;
          break;
      case 0:
        i++;
        if (i >= matchCount) {
            printf("No more recommendations available.\n");
            running = 0;
            }
        break;
      default:
        printf("Wrong input! Type 1 for yes or 0 for no!\n");
        break;
        }
    }
}
