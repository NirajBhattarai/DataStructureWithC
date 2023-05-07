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