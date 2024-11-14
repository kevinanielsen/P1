#ifndef ratings_H
#define ratings_H

typedef struct Ratings{
    const char *title; 
    int rating;        
} Ratings;

// Function prototypes, macros, etc.
Ratings *rate10Movies(Ratings *ratings);

#endif //ratings_H
