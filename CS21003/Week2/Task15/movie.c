// FILE: movie.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "movie.h"

void displayMovie(Movie *infoToDisplay)
{
    printf("\nName: %s\nRuntime: %d\nRating: %.1lf\n", infoToDisplay->name, infoToDisplay->runTime, infoToDisplay->rating);
    return;
}

void displayMovieArray(Movie *arrayToDisplay[], int size)
{
    for (int i=0; i<size; i++){
        printf("\nMovie %d\nName: %s\nRuntime: %d\nRating: %.1lf\n", i+1, arrayToDisplay[i]->name, arrayToDisplay[i]->runTime, arrayToDisplay[i]->rating);
    }
    return;
}

void initialiseMovie(Movie *movieToInitialise)
{
    strcpy(movieToInitialise->name, "!default!");
    movieToInitialise->runTime = 0;
    movieToInitialise->rating = 0.0;
    return;
}

void getMovieRunTime(Movie *infoToGet, int *newRunTime)
{
    *newRunTime = infoToGet->runTime;
    return;
}

void cloneMovie(Movie *movieToClone, Movie *movieToReceive)
{
    *movieToReceive = *movieToClone;
    return;
}