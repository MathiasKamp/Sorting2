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


void merge(int *pRandomNumberArray, int leftSideArray, int midArray, int rightSideArray) {

    // allocate temporary memory to hold the merged sub-arrays
    int *temp = (int *) malloc((rightSideArray - leftSideArray + 1) * sizeof(int));
    int i = leftSideArray, j = midArray + 1, k = 0;

    while (i <= midArray && j <= rightSideArray) {
        if (pRandomNumberArray[i] < pRandomNumberArray[j]) {
            temp[k++] = pRandomNumberArray[i++];
        } else {
            temp[k++] = pRandomNumberArray[j++];
        }
    }

    while (i <= midArray) {
        temp[k++] = pRandomNumberArray[i++];
    }

    while (j <= rightSideArray) {
        temp[k++] = pRandomNumberArray[j++];
    }

    for (i = leftSideArray; i <= rightSideArray; i++) {
        pRandomNumberArray[i] = temp[i - leftSideArray];
    }

    free(temp);  // free the temporary memory
}

void mergeSort(int *pRandomNumberArray, int leftSideArray, int rightSideArray) {

    if (leftSideArray < rightSideArray) {
        int mid = (leftSideArray + rightSideArray) / 2;

        mergeSort(pRandomNumberArray, leftSideArray, mid);
        mergeSort(pRandomNumberArray, mid + 1, rightSideArray);

        merge(pRandomNumberArray, leftSideArray, mid, rightSideArray);
    }
}

void runSort(int sizeOfArray) {

    int numberArray[sizeOfArray];

    generateRandomArray(sizeOfArray, numberArray);

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    mergeSort(numberArray, 0, sizeOfArray - 1);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf(" took : %f seconds\n", cpu_time_used);

}

void runTests() {
    int size;

    size = 1000;

    printf("running mergeSort on %d random numbers", size);

    runSort(size);

    size = 10000;

    printf("running mergeSort on %d random numbers", size);

    runSort(size);

    size = 100000;

    printf("running mergeSort on %d random numbers", size);

    runSort(size);

    size = 200000;

    printf("running mergeSort on %d random numbers", size);

    runSort(size);

    size = 500000;

    printf("running mergeSort on %d random numbers", size);

    runSort(size);
}


int main() {

    runTests();

    return 0;
}