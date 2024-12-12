#include <stdio.h>

int accountCheck(){
  char answer;
  printf("Do you have an account? (y/n)\n");
  scanf(" %c", &answer);
  if (answer == 'n'){
    printf("Enter a new username and rate 10 movies. \n");
    return 1;
  }
  else if (answer == 'y'){
    printf("Enter your username and choose a Genre. \n");
    return 0;
  }
  else{
    printf("Invalid input\n");
    return -1;
  }
}