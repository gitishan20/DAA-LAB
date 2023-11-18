#include <stdio.h>
#include <limits.h>

#define MAX 100

void matrixChainOrder(int p[], int n, int m[][MAX], int s[][MAX]) {
    int i, j, k, l, q;
    for (i = 1; i <= n; i++) {
        m[i][i] = 0;
    }
    for (l = 2; l <= n; l++) {
        for (i = 1; i <= n - l + 1; i++) {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printOptimalParenthesis(int s[][MAX], int i, int j) {
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
    int n, i, j, k, l, q;
    int p[MAX], m[MAX][MAX] = {0}, s[MAX][MAX] = {0};
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    for (i = 1; i <= n + 1; i++) {
        printf("Enter row and col size of A%d: ", i);
        scanf("%d %d", &p[i - 1], &p[i]);
    }
    matrixChainOrder(p, n, m, s);
    printf("M Table:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i <= j) {
                printf("%d ", m[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("S Table:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i < j) {
                printf("%d ", s[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("Optimal parenthesization: ");
    printOptimalParenthesis(s, 1, n);
    printf("\n");
    printf("The optimal ordering of the given matrices requires %d scalar multiplications.\n", m[1][n]);
    return 0;
}
