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

int getPartition(int *pRandomNumbers, int low, int high) {

    int pivot = pRandomNumbers[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {

        if (pRandomNumbers[j] < pivot) {

            i++;
            swap(&pRandomNumbers[i], &pRandomNumbers[j]);
        }
    }
    swap(&pRandomNumbers[i + 1], &pRandomNumbers[high]);
    return (i + 1);
}


void quickSort(int *pRandomNumbers, int low, int high) {

    if (low < high) {

        int partition = getPartition(pRandomNumbers, low, high);

        quickSort(pRandomNumbers, low, partition - 1);

        quickSort(pRandomNumbers, partition + 1, high);
    }
}


void runSort(int sizeOfArray) {

    int numberArray[sizeOfArray];

    generateRandomArray(sizeOfArray, numberArray);

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    quickSort(numberArray, 0, 100 - 1);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf(" took : %f seconds\n", cpu_time_used);

}

void runTests() {

    int size;

    size = 1000;

    printf("running quickSort on %d random numbers", size);

    runSort(size);

    size = 10000;

    printf("running quickSort on %d random numbers", size);

    runSort(size);

    size = 100000;

    printf("running quickSort on %d random numbers", size);

    runSort(size);

    size = 200000;

    printf("running quickSort on %d random numbers", size);

    runSort(size);

    size = 500000;

    printf("running quickSort on %d random numbers", size);

    runSort(size);
}


void runWithDebugInformation(){
    int numberArray[100];

    generateRandomArray(100, numberArray);

    printf("before quicksort : \n");

    printArray(numberArray, 100);

    quickSort(numberArray, 0, 100 - 1);

    printf("\nafter quicksort : \n");

    printArray(numberArray, 100);
}

int main() {

    runTests();

    return 0;
}
