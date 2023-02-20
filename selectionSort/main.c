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

void sort(int *numberArray, int size) {

    int i, j, min_idx;

    for (i = 0; i < size - 1; i++) {

        min_idx = i;

        for (j = i + 1; j < size; ++j) {


            if (numberArray[j] < numberArray[min_idx]) {

                min_idx = j;

            }

            if (min_idx != i) {

                // swap index j and i if j's value is < i value
                swap(&numberArray[min_idx], &numberArray[i]);
            }
        }
    }
}

void runSort(int sizeOfArray) {

    int numberArray[sizeOfArray];

    clock_t start, end;
    double cpu_time_used;

    generateRandomArray(sizeOfArray, numberArray);

    start = clock();

    sort(numberArray, sizeOfArray);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("time elapsed : %f seconds\n", cpu_time_used);

}

void runTests() {

    int size;

    size = 1000;

    printf("running selectionSort on %d random numbers. ", size);

    runSort(size);

    size = 10000;

    printf("running selectionSort on %d random numbers. ", size);

    runSort(size);

    size = 100000;

    printf("running selectionSort on %d random numbers. ", size);

    runSort(size);

    size = 200000;

    printf("running selectionSort on %d random numbers. ", size);

    runSort(size);

    size = 300000;

    printf("running selectionSort on %d random numbers. ", size);

    runSort(size);
}


int main() {

    runTests();

    return 0;
}