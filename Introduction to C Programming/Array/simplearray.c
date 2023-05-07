#include <stdio.h>

int main() {
    int numbers[5];
    int sum = 0;
    float average;

    printf("Enter 5 integers:\n");

    // Reading and storing the integers in the array
    for (int i = 0; i < 5; i++) {
        scanf("%d", &numbers[i]);
    }

    // Calculating the sum of the integers
    for (int i = 0; i < 5; i++) {
        sum += numbers[i];
    }

    // Calculating the average
    average = (float)sum / 5;

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);

    return 0;
}
