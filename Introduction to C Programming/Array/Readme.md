# Array in C

## Table of Contents
1. Introduction to Arrays
2. Array Declaration and Initialization
3. Accessing and Modifying Array Elements
4. Iterating Over Arrays
5. Multidimensional Arrays
6. Passing Arrays to Functions
7. Dynamic Memory Allocation
8. Array Limitations

## Introduction to Arrays
An array is a collection of elements of the same data type, stored in contiguous memory locations. Arrays make it easy to work with large sets of data, allowing you to access and manipulate elements using a single variable name and an index.

```
int numbers[5]; // An array of 5 integers
```

## Array Declaration and Initialization

To declare an array, you need to specify the data type of its elements, the name of the array, and the size of the array in square brackets.

```
int ages[5]; // An array of 5 integers

```

You can also initialize the array at the time of declaration:

```
int ages[5] = {16, 21, 25, 30, 35};

```

Or, let the compiler automatically determine the size based on the number of elements provided:

```
int ages[] = {16, 21, 25, 30, 35}; // The size is automatically set to 5
``` 

## Accessing and Modifying Array Elements

To access or modify an element of an array, use the array name followed by the index of the element in square brackets. Note that array indices start at 0.

```
ages[2] = 26; // Modify the third element in the array
int age = ages[1]; // Access the second element in the array
```

## Iterating Over Arrays
You can use a loop to iterate over the elements of an array. The most common approach is to use a for loop:

```
for (int i = 0; i < 5; i++) {
    printf("Element at index %d: %d\n", i, ages[i]);
}
```

## Passing Arrays to Functions

When passing arrays to functions, you need to specify the data type and the size of the array. The array itself is passed as a pointer to its first element:

```

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

```


## Dynamic Memory Allocation

Instead of using static arrays, you can also allocate memory dynamically for arrays using the `malloc` calloc, and realloc` functions. This allows you to create arrays with sizes that are determined at runtime:

```
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Enter the size of the array: ");
  scanf("%d", &n);

  int *arr = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    printf("Enter element %d: ", i);
    scanf("%d", &arr[i]);
  }

  // Use the array...

  // Free the allocated memory when no longer needed
  free(arr);

  return 0;
}
```

## Program 1 

```

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

```

Output: 

```
Enter 5 integers:
1 2 3 4 5 
Sum: 15
Average: 3.00
```

## Dynamic Memory Allocation

In C, you can create a dynamic array using pointers and memory allocation functions like malloc() or calloc(). Here's an example of a program that creates a dynamic array, takes input from the user, and calculates the sum and average of the numbers.

```
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
        scanf("%d", &numbers[i]);
    }

    // Calculating the sum of the integers
    for (int i = 0; i < n; i++) {
        sum += numbers[i];
    }

    // Calculating the average
    average = (float)sum / n;

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);

    // Freeing the allocated memory
    free(numbers);

    return 0;
}
```

```
Enter the number of elements you want to store: 5
Enter 5 integers:
2 4 6 8 10
Sum: 30
Average: 6.00
```

In Above C program, memory is allocated in different segments: code, data, stack, and heap. Let's examine how the dynamic_array.c program allocates memory in these segments:

1. Code segment: This is where the compiled code (instructions) of the program resides. When you compile the program using the gcc command, the compiled code will be stored in the generated executable file (dynamic_array). When the program runs, this code is loaded into memory in the code segment.

2. Data segment: This is where global and static variables are stored. In the dynamic_array.c program, there are no global or static variables, so no memory will be allocated in the data segment for this program.

3. Stack segment: The stack segment is used for function call management, local variables, and function parameters. In the dynamic_array.c program, the following items will be stored on the stack:

The local variables n, sum, average, and i in the main function.
The function call information, such as the return address, for any called functions (e.g., printf, scanf, malloc, and free).
The pointer variable numbers in the main function. Note that the pointer itself will be on the stack, but the memory it points to will be in the heap segment.
Heap segment: The heap is used for dynamically allocated memory. In the dynamic_array.c program, the memory allocated for the dynamic array is stored in the heap. This memory is allocated using the malloc() function and freed using the free() function.
```
+--------------------+
|     Code Segment   |
|  (compiled code)   |
+--------------------+
|    Data Segment    |
| (no variables here)|
+--------------------+
|     Stack Segment  |
|--------------------|
|   Return Address   |
|    (for printf)    |
|--------------------|
|   Return Address   |
|    (for scanf)     |
|--------------------|
|   Return Address   |
|    (for malloc)    |
|--------------------|
|   Return Address   |
|    (for free)      |
|--------------------|
|  Local variable i  |
|--------------------|
| Local variable sum |
|--------------------|
|Local variable average|
|--------------------|
| Local variable n   |
|--------------------|
| Pointer variable   |
|     numbers        |
+--------------------+
|     Heap Segment   |
|--------------------|
| Dynamically allo-  |
| cated array memory |
|   (numbers[0...n-1])|
+--------------------+

```




