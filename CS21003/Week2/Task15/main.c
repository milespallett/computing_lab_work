#include <stdio.h>
#include <stdlib.h>
#include "movie.h"

int main(){

    Movie *pUserMovieArray = NULL;
    if (((Movie*) malloc(sizeof(Movie) * 3)) != NULL){
        pUserMovieArray = (Movie*) malloc(sizeof(Movie) * 3);
    }
    else {printf("error. quitting...");return 0;}

    for (int i=0; i<3; i++){
        Movie newMovie;
        initialiseMovie(&newMovie);

        printf("Movie name (Input in camel case): ");
        scanf("%s", &newMovie.name);
        printf("Movie runtime (minutes): ");
        scanf("%d", &newMovie.runTime);
        printf("Movie rating: ");
        scanf("%lf", &newMovie.rating);

        cloneMovie(&newMovie, &pUserMovieArray[i]);
    }

    displayMovieArray(&pUserMovieArray, 3);

    printf("enter any character to quit.....");
    scanf("%s");

    printf("\n\nCOMPLETE...QUITTING........");
    return 0;
}