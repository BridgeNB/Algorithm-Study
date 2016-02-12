/*The reason that I am writing this function is to understand further understanding 
on divide and conquer algorithm application on sorting*/

#include <stdlib.h>
#include <stdio.h>

void swap (int *array, int a, int b) {
    if (a != b) {
        array[a] = array[a] ^ array[b];
        array[b] = array[a] ^ array[b];
        array[a] = array[a] ^ array[b];
    }
    return;
}

int partition (int *array, int low, int high) {
    int p = low - 1; // p is the location of the last smaller element

    for (; low <= high; low++) {
        if (array[low] <= array[high]) {
            // swap the smaller element with the first larger element
            p++;

            if (p != low) {
                swap(array, p, low);
            }
        }
    }

    return p;
}

void quickSort (int *array, int low, int high) {

    if (low < high) {
        // start with the last element as pivot
        int mid = partition(array, low, high);

        if (low < mid - 1) {
            quickSort(array, low, mid - 1);
        } 

        if (high > mid + 1) {
            quickSort(array, mid + 1, high);
        }

    }

    return;

}

int main () {
    int A[] = {15, 7, 12, 43, 1, 23, 11, 14, 57, 12};

    int i, numOfEle;

    numOfEle = sizeof(A) / sizeof(A[0]);

    for (i = 0; i < numOfEle ; i++) {
        printf ("%d ", A[i]);
    }

    quickSort(A, 0, numOfEle-1);

    printf("\nAfter sorted: \n");

    for (i = 0; i < numOfEle; i++ ) {
        printf("%d ", A[i]);
    }

    return 0;
}
