# include <stdio.h>
# include <stdbool.h>

int main()
{
    //data structures (had to hard code values due to c not supporting variable-length arrays)
    int maximum[5][3];
    int allocation[5][3];
    int need[5][3];
    int available[3];

    //working variables (had to hard code again for same reason)
    int work[3];
    bool finish[5] = {false, false, false, false, false};
    int safeSequence[10] = {0};

    //input matrix values
    printf("Input values for 'maximum' matrix (left to right)");
    for (int i=0; i<5; i++){
        for (int j=0; j<3; j++){
            scanf("%d", &maximum[i][j]);
        }
    }

    printf("Maximum matrix:\n");
    for (int i=0; i<5; i++){
        for (int j=0; j<3; j++){
            printf("%d ", maximum[i][j]);
        }
        printf("\n");
    }

    printf("Input values for 'allocation' matrix (left to right)");
    for (int i=0; i<5; i++){
        for (int j=0; j<3; j++){
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Allocation matrix:\n");
    for (int i=0; i<5; i++){
        for (int j=0; j<3; j++){
            printf("%d ", allocation[i][j]);
        }
        printf("\n");
    }

    printf("Input values for 'available' matrix (left to right)");
    for (int i=0; i<3; i++){
        scanf("%d", &available[i]);
    }

    printf("Available matrix:\n");
    for (int i=0; i<3; i++){
        printf("%d %1", available[i]);
    }
    printf("\n");

    //calculate need matrix
    printf("\nCalculating 'need' matrix...\n");

    for (int i=0; i<5; i++){
        for (int j=0; j<3; j++){
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    printf("Need matrix:\n");
    for (int i=0; i<5; i++){
        for (int j=0; j<3; j++){
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    //copy values of available into work
    for (int i=0; i<3; i++){
        work[i] = available[i];
    }

    //main algorithm loop
    int count = 0;

    do{
        bool found = false; // check if found a process to execute

        for (int i=0; i<5; i++){
            if (finish[i] == false){ //check if process has finished yet

                //check if processes needs can be satisfied
                bool canExecute = true;
                for (int j=0; j<3; j++){
                    if(need[i][j] > work[j]){
                        canExecute = false;
                    }
                }

                //if process can execute, simulate execution
                if (canExecute == true){
                    //add allocated resources back to work[]
                    for (int j=0; j<3; j++){
                        work[j] = work[j] + allocation[i][j];
                    }

                    //mark process as finished
                    finish[i] = true;
                    
                    bool emptyCheck = false;
                    for (int j=0; j<10; j++){
                        if (safeSequence[j] == 0){
                            emptyCheck = true;
                        }
                        if (emptyCheck == true){
                            safeSequence[j] = i;
                            count++;
                            found = true;
                        }
                    }
                }
            }
        }
        if (found == false){ // if no process is found in this iteration, system is unsafe
            printf("System is unsafe");
            break;
        }
    }while (count < 0);

    for (int i=0; i<5; i++){
        if (safeSequence[i] == true){
            printf("safe\n");
        }
        else if (safeSequence[i] == false){
            printf("unsafe\n");
        }
    }
}