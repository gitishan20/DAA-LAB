#include <stdio.h>

void decimalToBinary(int decimal) {
    if (decimal > 0) {
        decimalToBinary(decimal / 2);
        printf("%d", decimal % 2);
    }
}

int main() {
    int n;

    printf("Enter the number of decimal numbers: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int decimal;
        printf("Enter decimal number #%d: ", i + 1);
        scanf("%d", &decimal);

        printf("Binary representation of %d: ", decimal);
        decimalToBinary(decimal);
        printf("\n");
    }

    return 0;
}
