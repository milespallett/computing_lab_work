#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void initialiseMovie(movieInfo *movieToInitialise){
    strcpy(movieToInitialise->movieName, "!default!");
    movieToInitialise->movieRunTime = 0;
    movieToInitialise->movieRating = 0.0;
}

int getMovieRunTime(movieInfo *infoToGet){
    return infoToGet->movieRunTime;
}

void getMovieRunTime1(movieInfo *infoToGet, int *runTime){
    *runTime = infoToGet->movieRunTime;
}

void cloneMovie(movieInfo *movieToClone, movieInfo *movieToRecieve){
    *movieToRecieve = *movieToClone;
}

int main()
{

    char userMovieName[150];
    int userMovieRunTime;
    double userMovieRating;

    

    //Task 13
    /*
    movieInfo movie;
    initialiseMovie(&movie);
    movie.movieRunTime = 123;

    movieInfo movie1;
    
    cloneMovie(&movie, &movie1);

    displayMovieInformation1(&movie1);
    */

    //Task 12
    /*
    movieInfo movie;
    movie.movieRunTime = 123;

    int runningTime = 0;

    getMovieRunTime1(&movie, &runningTime);

    printf("Movie runtime is %d.", runningTime);
    */


    //Task 11
    /*
    movieInfo movie;
    movie.movieRunTime = 123;

    int runningTime = 0;

    runningTime = getMovieRunTime(&movie);

    printf("Movie runtime is %d.", runningTime);
    */


    //Task 10
    /*
    movieInfo movie;

    initialiseMovie(&movie);

    displayMovieInformation1(&movie);
    */

    //Task 9
    /*
    movieInfo *pUserMovieArray = NULL;
    if (((movieInfo*) malloc(sizeof(movieInfo) * 3)) != NULL){
        pUserMovieArray = (movieInfo*) malloc(sizeof(movieInfo) * 3);
    }
    else {printf("error. quitting...");return 0;}

    for (int i=0; i<3; i++){
        strcpy(pUserMovieArray[i].movieName, "Moon");
        pUserMovieArray[i].movieRunTime = 97;
        pUserMovieArray[i].movieRating = 7.8;
    }

    displayMovieArray(pUserMovieArray, 3);
    */


    //Task 8
    /*
    if ((movieInfo *) malloc(sizeof(*pMovieInfo)) != NULL){
        pMovieInfo = (movieInfo *) malloc(sizeof(*pMovieInfo));
        printf("success");
    }
    else{printf("Not enough memory space... exiting...");return 0;}

    strcpy(pMovieInfo->movieName, "Moon");
    pMovieInfo->movieRunTime = 97;
    pMovieInfo->movieRating = 7.8;
    
    displayMovieInformation1(pMovieInfo);
    */

    
    //Tasks 6-7
    /*
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
    */


    //Tasks 1-5
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