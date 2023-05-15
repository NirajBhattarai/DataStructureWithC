# Sorting

Sorting is the process of arranging data (usually a collection of items) in a specific order, either ascending or descending, based on a certain property or criterion. This process helps in organizing and analyzing data more effectively. Sorting algorithms are widely used in computer science and various applications, such as database management, data analysis, and computer graphics.

Sorting can be broadly classified into two categories: Internal Sorting and External Sorting.

## Internal Sorting

Internal sorting algorithms are used when the entire dataset fits into the main memory (RAM) of the computer. The sorting process occurs within the main memory without using any external storage devices like hard disks. Some common internal sorting algorithms include:

1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
5. Quick Sort
6. Heap Sort

## External Sorting

External sorting algorithms are used when the dataset is too large to fit into the main memory, and the sorting process needs to be performed using external storage devices (e.g., hard disks). These algorithms divide the dataset into smaller chunks that can be loaded into the main memory, sort the chunks individually, and then merge the sorted chunks to produce the final sorted dataset. External sorting algorithms typically use techniques like multi-way merging and polyphase merging. One common example of an external sorting algorithm is the External Merge Sort.

## Selection Sort

Selection sort is a simple comparison-based sorting algorithm. The main idea behind selection sort is to divide the input list into two parts: the sorted part and the unsorted part. Initially, the sorted part is empty, and the unsorted part contains all the elements. The algorithm repeatedly selects the smallest (or largest, depending on the desired order) element from the unsorted part and moves it to the end of the sorted part. This process continues until the unsorted part becomes empty and the sorted part contains all the elements in the desired order.

Here is a step-by-step explanation of the selection sort algorithm:

1. Find the minimum (or maximum) element in the unsorted part of the list, and its index.
2. Swap this minimum (or maximum) element with the first element in the unsorted part.
3. Move the boundary between the sorted and unsorted parts one element to the right.
4. Repeat steps 1-3 until the entire list is sorted.
   The time complexity of selection sort is O(n^2), where n is the number of elements in the list. This makes it inefficient for large datasets.

Here's an example of selection sort implemented in C:

```
#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
```

## Bubble Sort

Bubble sort is a simple comparison-based sorting algorithm. The main idea behind bubble sort is to repeatedly step through the list, compare adjacent elements, and swap them if they are in the wrong order. This process is repeated until the list is sorted. The algorithm gets its name because the smaller elements "bubble" to the top of the list, while the larger elements "sink" to the bottom.

Here is a step-by-step explanation of the bubble sort algorithm:

1. Iterate through the list from the beginning to the second-to-last element.
2. Compare the current element with the next element.
3. If the current element is greater than the next element (for ascending order), swap them.
4. Repeat steps 1-3 for the entire list until no swaps are performed during a complete iteration.

The time complexity of bubble sort is O(n^2), where n is the number of elements in the list. This makes it inefficient for large datasets.

Here's an example of bubble sort implemented in C:

```
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        // If no swaps are performed during an iteration, the array is already sorted.
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
```
## Selection Sort

The selection sort algorithm divides the input array into two parts: the sorted part and the unsorted part. The sorted part is initially empty, and the unsorted part contains all the elements. The algorithm repeatedly selects the smallest (or largest, depending on the order) element from the unsorted part and swaps it with the first element of the unsorted part, thereby expanding the sorted part by one element. This process continues until the entire array is sorted.

In the implementation above, the selectionSort function takes an array arr and its length n as input. It uses two nested loops to find the minimum element in the unsorted part of the array and swaps it with the current element. The outer loop iterates through the array from the first element to the second-to-last element, while the inner loop searches for the minimum element starting from the next element. After each iteration of the outer loop, the minimum element is placed in its correct sorted position. The process is repeated until the array is completely sorted

```
#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    // Iterate through the array
    for (i = 0; i < n - 1; i++) {
        minIndex = i; // Assume the current index contains the minimum value

        // Find the minimum element in the remaining unsorted part of the array
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the minimum element with the current element
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf("Original array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selectionSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


```
