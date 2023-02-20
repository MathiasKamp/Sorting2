#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomArray(int size, int array[]) {

    int i;
    // seed the random number generator with current time to make it unpredictable
    srand(time(NULL));

    for (i = 0; i < size; i++) {

        array[i] = rand() % (2147483647 - 1 + 1) + 1; // generate number between 1 and int max 2147483647 - 1
    }
}

void printArray(int array[], int size) {

    for (int i = 0; i < size; ++i) {

        printf("%d ", array[i]);

    }
}


void swap(int *x, int *y) {
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void insertionSort(int *pRandomNumbers, int size) {

    int i, tmpNumber, j;

    for (i = 1; i < size; i++) {

        tmpNumber = pRandomNumbers[i];

        j = i - 1;

        while (j >= 0 && pRandomNumbers[j] > tmpNumber) {


            pRandomNumbers[j + 1] = pRandomNumbers[j];
            j = j - 1;
        }

        pRandomNumbers[j + 1] = tmpNumber;

    }
}



void runSort(int sizeOfArray) {

    int numberArray[sizeOfArray];

    generateRandomArray(sizeOfArray, numberArray);

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    insertionSort(numberArray, sizeOfArray);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf(" took : %f seconds\n", cpu_time_used);

}

void runTests(){

    int size;

    size = 1000;

    printf("running insertionSort on %d random numbers", size);

    runSort(size);

    size = 10000;

    printf("running insertionSort on %d random numbers", size);

    runSort(size);

    size = 100000;

    printf("running insertionSort on %d random numbers", size);

    runSort(size);

    size = 200000;

    printf("running insertionSort on %d random numbers", size);

    runSort(size);

    size = 500000;

    printf("running insertionSort on %d random numbers", size);

    runSort(size);
}

int main() {
    
    runTests();

    return 0;
}
