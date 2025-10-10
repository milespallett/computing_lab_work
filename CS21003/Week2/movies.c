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

int main()
{
    movieInfo userMovie;

    char userMovieName[150];
    int userMovieRunTime;
    double userMovieRating;

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

    return 0;
}