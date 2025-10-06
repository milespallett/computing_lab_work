#include <stdio.h>

int displayResults(float outputArray[5])
{
    int i;
    float total;
    float average;
    float quickestTime;
    int quickestCompetitor;

    for (i = 1; i <= 5; i++) {
        printf("\nCompetitor %d: %f seconds.", i, outputArray[i]);

        total = total + outputArray[i];

        if (outputArray[i] < quickestTime || quickestTime == 0){
            quickestTime = outputArray[i];
            quickestCompetitor = i;
        }
    }
    
    average = total / 5;
    printf("\n\nMean time: %f seconds.", average);

    printf("\n\nQuickest time is %f seconds by Competitor %d", quickestTime, quickestCompetitor);

    return 0;
}

int main()
{
    int j;
    float inputArray[5];

    for (j = 1; j <= 5; j++) {
        printf("Input result number %d: ", j);
        scanf("%f", &inputArray[j]);
    }

    displayResults(inputArray);

    return 0;
}