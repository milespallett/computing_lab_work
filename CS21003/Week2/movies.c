#include <stdio.h>
#include <string.h>

struct MovieInformation{
    int movieRunTime;
    char movieName[150];
    double movieRating;
};

typedef struct MovieInformation movieInfo;

movieInfo *pMovieInfo = NULL;

void displayMovieInformation(movieInfo infoToDisplay)
{
    printf("\nName: %s\nRuntime: %d\nRating: %.1lf\n", infoToDisplay.movieName, infoToDisplay.movieRunTime, infoToDisplay.movieRating);
    return;
}

void displayMovieInformation1(movieInfo *infoToDisplay){
    printf("\nName: %s\nRuntime: %d\nRating: %.1lf\n", infoToDisplay->movieName, infoToDisplay->movieRunTime, infoToDisplay->movieRating);
    return;
}

void displayMovieArray(movieInfo arrayToDisplay[], int size){
    for (int i=0; i<size; i++){
        printf("\nMovie %d\nName: %s\nRuntime: %d\nRating: %.1lf\n", i+1, arrayToDisplay[i].movieName, arrayToDisplay[i].movieRunTime, arrayToDisplay[i].movieRating);
    }
    return;
}

int main()
{

    char userMovieName[150];
    int userMovieRunTime;
    double userMovieRating;

    movieInfo userMovieArray[3];

    for (int i=0; i<3; i++){
        printf("Movie name (Input in camel case): ");
        scanf("%s", &userMovieArray[i].movieName);
        printf("Movie runtime (minutes): ");
        scanf("%d", &userMovieArray[i].movieRunTime);
        printf("Movie rating: ");
        scanf("%lf", &userMovieArray[i].movieRating);
    }

    displayMovieArray(userMovieArray, (sizeof(userMovieArray)/sizeof(userMovieArray[0])));

    /*
    movieInfo userMovie;
    printf("Movie name: ");
    scanf("%s", &userMovieName);
    printf("Movie runtime (minutes): ");
    scanf("%d", &userMovieRunTime);
    printf("Movie rating: ");
    scanf("%lf", &userMovieRating);

    pMovieInfo = &userMovie;
    strcpy((*pMovieInfo).movieName, userMovieName);
    (*pMovieInfo).movieRunTime = userMovieRunTime;
    (*pMovieInfo).movieRating = userMovieRating;

    displayMovieInformation1(pMovieInfo);
    */

    return 0;
}