// Convert n decimal no's from a disc to binary using recursion
#include <stdio.h>

int getGCD(int n1, int n2) {
    if (n2 != 0)
        return getGCD(n2, n1 % n2);
    else
        return n1;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("2105884 Gitishan\n");
        printf("Usage: ./gcd <source_file> <destination_file>\n");
        return 1;
    }

    FILE *sorFile = fopen(argv[1], "r");
    if (sorFile == NULL) {
        printf("Error opening source file.\n");
        return 1;
    }

    FILE *destFile = fopen(argv[2], "w");
    if (destFile == NULL) {
        printf("Error opening destination file.\n");
        fclose(sorFile);
        return 1;
    }

    int n1, n2;

    while (fscanf(sorFile, "%d %d", &n1, &n2) != EOF) {
        int result = getGCD(n1, n2);
        fprintf(destFile, "The GCD of %d and %d is %d\n", n1, n2, result);
    }

    fclose(sorFile);
    fclose(destFile);

    printf("Task Completed check the file.\n");

    return 0;
}