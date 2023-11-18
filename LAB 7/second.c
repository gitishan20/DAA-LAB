#include <stdio.h>
#include <string.h>
void LCS(char str1[], char str2[]) {
    int n = strlen(str1);
    int m = strlen(str2);
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }
    int len = dp[n][m];
    char lcs[len + 1];
    lcs[len] = '\0';
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs[len - 1] = str1[i - 1];
            i--;
            j--;
            len--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    printf("\nLCS : %s\n", lcs);
    printf("LCS Length : %d\n", dp[n][m]);
}
int main() {
    printf ("2105884 Gitishan\n");
    
    char Str1[50], Str2[50];
    printf("Enter the first string : ");
    scanf("%s", Str1);
    printf("Enter the second string : ");
    scanf("%s", Str2);
    LCS(Str1, Str2);
    return 0;
}