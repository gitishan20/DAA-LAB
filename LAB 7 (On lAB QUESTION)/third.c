
#include <stdio.h>
#include <math.h>

// Define the number of data points
#define N 6

// Function to calculate the coefficients for a linear equation (Y = A * X + B)
void linearRegression(double x[], double y[], double *A, double *B) {
    double sumX = 0.0, sumY = 0.0, sumXY = 0.0, sumX2 = 0.0;

    for (int i = 0; i < N; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    *A = (N * sumXY - sumX * sumY) / (N * sumX2 - sumX * sumX);
    *B = (sumY - *A * sumX) / N;
}

// Function to calculate the coefficients for a quadratic equation (Y = A * X^2 + B * X + C)
void quadraticRegression(double x[], double y[], double *A, double *B, double *C) {
    double sumX = 0.0, sumY = 0.0, sumX2 = 0.0, sumX3 = 0.0, sumX4 = 0.0, sumXY = 0.0, sumX2Y = 0.0;

    for (int i = 0; i < N; i++) {
        double xi = x[i];
        sumX += xi;
        sumY += y[i];
        sumX2 += xi * xi;
        sumX3 += xi * xi * xi;
        sumX4 += xi * xi * xi * xi;
        sumXY += xi * y[i];
        sumX2Y += xi * xi * y[i];
    }

    *A = (sumX2Y * sumX2 - sumX3 * sumXY) / (sumX4 * sumX2 - sumX3 * sumX3);
    *B = (sumXY - *A * sumX3) / sumX2;
    *C = (sumY - *A * sumX2 - *B * sumX) / N;
}

// Function to calculate the coefficients for a cubic equation (Y = A * X^3 + B * X^2 + C * X + D)
void cubicRegression(double x[], double y[], double *A, double *B, double *C, double *D) {
    double sumX = 0.0, sumY = 0.0, sumX2 = 0.0, sumX3 = 0.0, sumX4 = 0.0, sumX5 = 0.0, sumX6 = 0.0, sumXY = 0.0, sumX2Y = 0.0;

    for (int i = 0; i < N; i++) {
        double xi = x[i];
        sumX += xi;
        sumY += y[i];
        sumX2 += xi * xi;
        sumX3 += xi * xi * xi;
        sumX4 += xi * xi * xi * xi;
        sumX5 += xi * xi * xi * xi * xi;
        sumX6 += xi * xi * xi * xi * xi * xi;
        sumXY += xi * y[i];
        sumX2Y += xi * xi * y[i];
    }

    *A = ((sumX2Y * (sumX2 * sumX2 - sumX4 * sumX)) - (sumX3 * (sumXY * sumX2 - sumX3 * sumY))) /
         ((sumX4 * (sumX2 * sumX2 - sumX4 * sumX)) - (sumX3 * (sumX3 * sumX2 - sumX4 * sumX3)));

    *B = ((sumXY * (sumX4 * sumX2 - sumX3 * sumX3)) - (sumX3 * (sumX2Y * sumX2 - sumX3 * sumY))) /
         ((sumX4 * (sumX2 * sumX2 - sumX4 * sumX)) - (sumX3 * (sumX3 * sumX2 - sumX4 * sumX3)));

    *C = ((sumX2Y * sumX4 * sumX2) - (sumX3 * sumXY * sumX2) - (sumX2 * sumX2 * sumY) +
          (sumX4 * sumX3 * sumY)) /
         ((sumX4 * (sumX2 * sumX2 - sumX4 * sumX)) - (sumX3 * (sumX3 * sumX2 - sumX4 * sumX3)));

    *D = ((sumX2Y * sumX4 * sumX3) - (sumX2 * sumX2 * sumX2Y) - (sumX4 * sumX3 * sumXY) +
          (sumX3 * sumX3 * sumX2Y)) /
         ((sumX4 * (sumX2 * sumX2 - sumX4 * sumX)) - (sumX3 * (sumX3 * sumX2 - sumX4 * sumX3)));
}

int main() {
    double x[] = {3, 6, 9, 12, 15, 18};
    double y[] = {9, 19, 29, 39, 49, 59};

    double linearA, linearB;
    double quadraticA, quadraticB, quadraticC;
    double cubicA, cubicB, cubicC, cubicD;

    linearRegression(x, y, &linearA, &linearB);
    quadraticRegression(x, y, &quadraticA, &quadraticB, &quadraticC);
    cubicRegression(x, y, &cubicA, &cubicB, &cubicC, &cubicD);

    double xValue = 10.0; // Change this value to calculate Y for different X

    // Calculate Y for linear equation
    double linearY = linearA * xValue + linearB;

    // Calculate Y for quadratic equation
    double quadraticY = quadraticA * xValue * xValue + quadraticB * xValue + quadraticC;

    // Calculate Y for cubic equation
    double cubicY = cubicA * xValue * xValue * xValue + cubicB * xValue * xValue + cubicC * xValue + cubicD;

    printf("For X = %.2f\n", xValue);
    printf("Linear Y = %.2f\n", linearY);
    printf("Quadratic Y = %.2f\n", quadraticY);
    printf("Cubic Y = %.2f\n", cubicY);

    return 0;
}