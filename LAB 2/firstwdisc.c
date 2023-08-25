#include <stdio.h>

void decimalToBinaryRecursion(int num, int bits) {
    if (bits == 0) {
        return;
    }
    decimalToBinaryRecursion(num / 2, bits - 1);
    printf("%d", num % 2);
}

int main() {
    int num;

    printf("Enter decimal numbers (Ctrl+Z or Ctrl+D to exit):\n");
    while (scanf("%d", &num) != EOF) {
        printf("The binary equivalent of %d is ", num);
        decimalToBinaryRecursion(num, 16);
        printf("\n");
    }

    printf("Conversion completed.\n");
    return 0;
}
