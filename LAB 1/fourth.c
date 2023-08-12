
#include <stdio.h>

void EXCHANGE(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void ROTATE_RIGHT(int *p1, int p2) {
    for (int i = p2 - 1; i >= 1; i--) {
        EXCHANGE(p1 + i, p1 + i - 1);
    }
}

int main() {
    int N;
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    int A[N];
    printf("Enter %d integers separated by spaces:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int p2;
    printf("Enter the number of elements to be rotated: ");
    scanf("%d", &p2);

    printf("Original array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    ROTATE_RIGHT(A, p2);

    printf("Array after rotating %d elements to the right: ", p2);
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}