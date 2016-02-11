/*The reason that I am writing this function is to understand divide and 
conquer algorithm strategy!*/


#include<stdio.h>
#include<stdlib.h>

void merge(int *A, int *L, int leftCount, int *R, int rightCount) {
    int i, j, k;

    i = 0;
    j = 0;
    k = 0;

    while (i < leftCount && j < rightCount) {
        if (L[i] < R[j]) 
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }

    // To put all the left overs
    while (i < leftCount) 
        A[k++] = L[i++];

    while (j < rightCount) 
        A[k++] = R[j++];

    return;
}

void mergeSort(int *A, int n) {
    int mid, i, *L, *R;

    // terminated when divided to only one element
    if (n < 2)
        return;

    mid = n / 2; 

    L = (int*)malloc(mid * sizeof(int));

    R = (int*)malloc((n - mid) * sizeof(int));

    for (i = 0; i < mid; i++) {
        L[i] = A[i];
    }

    for (i = mid; i < n; i++) {
        R[i - mid] = A[i];
    } 

    mergeSort (L, mid);
    // incase the array is odd length
    mergeSort (R, n - mid);

    merge(A, L, mid, R, n-mid);

    free(L);
    free(R);


}

int main() {
    int A[] = {5, 7, 12, 43, 1, 23, 21, 14, 57, 12};

    // // print all sorted elements once.
    // for(i = 0; i < numOfElements ; i++) printf("%d ", A[i]);

    int i, numOfElements;

    numOfElements = sizeof(A) / sizeof(A[0]);

    // print all sorted elements once.
    for(i = 0; i < numOfElements ; i++) printf("%d ", A[i]);

    // calling merge sort to sort the array
    mergeSort(A, numOfElements);

    // after sorted
    printf("\n After sorted \n");
    // print all sorted elements once.
    for(i = 0; i < numOfElements ; i++) printf("%d ", A[i]);

    return 0;
}