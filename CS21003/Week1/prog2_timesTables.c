#include <stdio.h>

int displayTable(int base, int multiplier)
{
    int result;
    int count = 1;
    do{
        result = base * count;
        printf("%d x %d = %d\n", base, count, result);
        count++;
    }
    while (count != multiplier + 1);

    return 0;
}

int main()
{
    int inputBase;
    int inputMultiplier;

    printf("What times table would you like to see?: ");
    scanf("%d", &inputBase);
    printf("How many multiplications would you like to see?: ");
    if (scanf("%d", &inputMultiplier) == 0){
        printf("Error: Invalid input - Shutting down...");
        return 0;
    } else if (inputMultiplier <= 0){
        printf("Error: Invalid input - Shutting down...");
        return 0;
    } else {
        displayTable(inputBase, inputMultiplier);
        return 0;
    }
    return 0;
}