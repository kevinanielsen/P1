#include "movie.h"
#include <stdio.h>
#include <string.h>

void searchGenre(Movie movies[], int movieCount, char *keyword,
                 int *searchedGenreIndex) {
  int foundCount = 0;
  int j = 0;
  for (int i = 0; i < movieCount; i++) {
    if (strstr(movies[i].genre, keyword) != NULL) {
      searchedGenreIndex[j] = i;
      foundCount++;
      j++;
    }
  }
  if (foundCount == 0) {
    printf("No movies found with genre containing '%s'.\n", keyword);
  }
}

void searchTheme(Movie movies[], int movieCount, char *keyword,
                 int *resultIndexes) {
  int foundCount = 0;
  int j = 0;
  for (int i = 0; i < movieCount; i++) {
    if (strstr(movies[i].theme, keyword) != NULL) {
      resultIndexes[j] = i;
      foundCount++;
      j++;
    }
  }
  if (foundCount == 0) {
    printf("No movies found with genre containing '%s'.\n", keyword);
  }
}

int getMovieByTitle(Movie movies[], int movieCount, char *title) {
  for (int i = 0; i < movieCount; i++) {

    // Locate the first and second apostrophe in `title`
    char *start = strchr(title, '\'');
    char *end = strrchr(title, '\'');

    if (start != NULL && end != NULL && start != end) {
      // Calculate the length of the substring between the apostrophes
      size_t length = end - start - 1;

      // Compare the substring with `movies[i].title`
      if (strncmp(movies[i].title, start + 1, length) == 0 &&
          movies[i].title[length] == '\0') {
        return i;
      }
    }
  }
  return -1;
}