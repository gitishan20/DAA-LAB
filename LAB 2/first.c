#include <stdio.h>
void decimalToBinaryRecursion(int num,int bits, FILE *dest_file) {
    // Base case: if number is 0
    if(bits == 0) {
        return;
    }
    decimalToBinaryRecursion(num / 2,bits-1, dest_file);
    fprintf(dest_file, "%d", num % 2);
}
int main() 
{
    FILE *src_file, *dest_file;
    int num;

    src_file = fopen("source.txt", "r");
    if(src_file == NULL) {
        printf("Unable to open source file.\n");
        return 1;
    }
    
    dest_file = fopen("dest.txt", "w");
    if(dest_file == NULL) {
        printf("Unable to create/open destination file.\n");
        return 1;
    }
    while(fscanf(src_file, "%d", &num) != EOF) {
        fprintf(dest_file, "The binary equivalent of %d is", num);
        decimalToBinaryRecursion(num,16, dest_file);
        fprintf(dest_file, "\n");
    }
    fclose(src_file);
    fclose(dest_file);
    printf("Conversion completed successfully.\n");
    return 0;
}