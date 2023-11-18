#include <stdio.h>
#include <limits.h>

#define MAX_MATRICES 10

void matrixChainOrder(int p[], int n, int m[MAX_MATRICES][MAX_MATRICES], int s[MAX_MATRICES][MAX_MATRICES]) {
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printOptimalParenthesis(int s[MAX_MATRICES][MAX_MATRICES], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int n, i;
    int p[MAX_MATRICES];

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter dimensions of matrices:\n");
    for (i = 0; i < n; i++) {
        printf("Enter row and column size of A%d: ", i + 1);
        scanf("%d %d", &p[i], &p[i + 1]);
    }

    int m[MAX_MATRICES][MAX_MATRICES];
    int s[MAX_MATRICES][MAX_MATRICES];

    matrixChainOrder(p, n, m, s);

    // Print M table
    printf("\nM Table:\n");
    for (i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    // Print S table
    printf("\nS Table:\n");
    for (i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }

    // Print optimal parenthesization
    printf("\nOptimal parenthesization: ");
    printOptimalParenthesis(s, 1, n);
    printf("\n");

    printf("The optimal ordering of the given matrices requires %d scalar multiplications.\n", m[1][n]);

    return 0;
}
