#include <stdio.h>

int main()
{
    char colour1[20];
    char colour2[20];
    char colour3[20];
    char colour4[20];
    char colour5[20];

    printf("Input 5 colours: \n");
    scanf("colour 1: %s\n", &colour1);
    scanf("colour 2: %s\n", &colour2);
    scanf("colour 3: %s\n", &colour3);
    scanf("colour 4: %s\n", &colour4);
    scanf("%s\n", &colour5);

    printf("colour 1: %s\n", colour1);
    printf("colour 2: %s\n", colour2);
    printf("colour 3: %s\n", colour3);
    printf("colour 4: %s\n", colour4);
    printf("colour 5: %s\n", colour5);
}