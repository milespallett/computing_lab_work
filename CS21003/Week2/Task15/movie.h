// FILE: movie.h

#ifndef __MOVIE_HEADER__
#define __MOVIE_HEADER__

typedef struct movie {
    char name[150];
    int runTime;
    double rating;
} Movie;

void displayMovie(Movie *infoToDisplay);
void displayMovieArray(Movie *arrayToDisplay[], int size);
void initialiseMovie(Movie *movieToInitialise);
void getMovieRunTime(Movie *infoToGet, int *newRunTime);
void cloneMovie(Movie *movieToClone, Movie *movieToReceive);

#endif