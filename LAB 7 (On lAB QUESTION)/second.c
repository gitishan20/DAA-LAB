
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Include the time.h header for the time function
#include <math.h>

int randomRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

double calculateMean(int data[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return (double)sum / n;
}

double calculateMedian(int data[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    if (n % 2 == 0) {
        return (double)(data[n / 2 - 1] + data[n / 2]) / 2;
    } else {
        return (double)data[n / 2];
    }
}

int calculateMode(int data[], int n) {
    int maxValue = 0, maxCount = 0;

    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (data[j] == data[i])
                count++;
        }

        if (count > maxCount) {
            maxCount = count;
            maxValue = data[i];
        }
    }

    return maxValue;
}

int main() {
    // Seed the random number generator
    srand(time(NULL)); // Include the time.h library for time

    int n = 100;
    int data[n];

    for (int i = 0; i < n; i++) {
        data[i] = randomRange(1, 50000);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    int classIntervals[] = {100, 500, 5000, 10000, 50000};
    int frequencies[5] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            if (data[i] <= classIntervals[j]) {
                frequencies[j]++;
                break;
            }
        }
    }

    int cumulativeFrequencies[5];
    cumulativeFrequencies[0] = frequencies[0];

    for (int i = 1; i < 5; i++) {
        cumulativeFrequencies[i] = cumulativeFrequencies[i - 1] + frequencies[i];
    }

    double mean = calculateMean(data, n);
    double median = calculateMedian(data, n);
    int mode = calculateMode(data, n);

    double sumSquaredDeviations = 0.0;

    for (int i = 0; i < n; i++) {
        sumSquaredDeviations += (data[i] - mean) * (data[i] - mean);
    }

    double variance = sumSquaredDeviations / n;
    double standardDeviation = sqrt(variance);

    printf("Class Interval\tMid Point\tFrequency\tCumulative Frequency\n");
    printf("100 to 500\t%d\t\t%d\t\t%d\n", (classIntervals[0] + classIntervals[1]) / 2, frequencies[0], cumulativeFrequencies[0]);
    printf("500 to 5000\t%d\t\t%d\t\t%d\n", (classIntervals[1] + classIntervals[2]) / 2, frequencies[1], cumulativeFrequencies[1]);
    printf("5000 to 10000\t%d\t\t%d\t\t%d\n", (classIntervals[2] + classIntervals[3]) / 2, frequencies[2], cumulativeFrequencies[2]);
    printf("10000 to 50000\t%d\t\t%d\t\t%d\n", (classIntervals[3] + classIntervals[4]) / 2, frequencies[3], cumulativeFrequencies[3]);
    printf("\nMean: %.2lf\n", mean);
    printf("Median: %.2lf\n", median);
    printf("Mode: %d\n", mode);
    printf("Variance: %.2lf\n", variance);
    printf("Standard Deviation: %.2lf\n", standardDeviation);

    return 0;
}