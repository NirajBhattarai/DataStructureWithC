#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *numbers;
    int sum = 0;
    float average;

    printf("Enter the number of elements you want to store: ");
    scanf("%d", &n);

    // Allocating memory for the dynamic array
    numbers = (int *)malloc(n * sizeof(int));
    if (numbers == NULL) {
        printf("Error: Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);

    
    // Reading and storing the integers in the dynamic array
    for (int i = 0; i < n; i++) {
        scanf("%d", numbers[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("\t %d", numbers[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("\t %d", *(numbers+i));
    }

    // Calculating the sum of the integers
    for (int i = 0; i < n; i++) {
        sum += numbers[i];
    }
     printf("\n");


    // Calculating the average
    average = (float)sum / n;

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);

      for (int i = 0; i < n; i++) {
        scanf("%d", (numbers+i));
    }

    // Freeing the allocated memory
    free(numbers);

    return 0;
}
