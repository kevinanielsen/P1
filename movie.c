#include "movie.h"
#include <stdio.h>

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

void recommendMovies(Movie *movie) {
  insertionSort(movie, 250);
  int i = 0;
  int running = 1;
  while (running) {
    int answer;
    printf("Our recommendation is: %s \n", movie[i].title);
    printf("Do you want to watch this movie? (1 = yes, 0 = no) \n");
    scanf(" %d", &answer);

    switch (answer) {
    case 1:
      running = 0;
      printf("Enjoy your movie! \n");
      break;
    case 0:
      i++;
      break;
    default:
      printf("Wrong input! Type 1 for yes or 0 for no!");
      break;
    }
  }
}
