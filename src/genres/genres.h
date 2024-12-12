#ifndef GENRES_H
#define GENRES_H

typedef enum Genres {
    ACTION,
    ADVENTURE_GENRE,
    ANIMATION,
    BIOGRAPHY,
    COMEDY_GENRE,
    CRIME,
    DRAMA,
    FAMILY_GENRE,
    FANTASY,
    FILM_NOIR,
    HISTORY,
    HORROR,
    MUSIC,
    MUSICAL,
    MYSTERY,
    ROMANCE,
    SCI_FI,
    SPORT,
    THRILLER,
    WAR,
    WESTERN,
    RETRO,
    NO_GENRE
} Genres;

void getGenre (Genres *genre); 
char* getGenreName(Genres genre);

#endif
