# QuickSort Algorithm

QuickSort is a highly efficient sorting algorithm and is based on the partitioning of an array of data into smaller arrays. A large array is partitioned into two arrays, one of which holds values smaller than the specified value, say pivot, based on which the partition is made and another array holds values greater than the pivot value.

QuickSort partitions an array and then calls itself recursively twice to sort the two resulting subarrays. This algorithm is quite efficient for large-sized data sets as its average and worst-case complexity are O(n log n), with space complexity of O(log n).


## Analysis
1. Time Complexity:

. Worst-case: O(n^2)
Average-case: O(n log n)
Best-case: O(n log n)
Space Complexity:

Worst-case: O(n)
Average-case: O(log n)
Despite the worst-case scenario being O(n^2), in practice, QuickSort is typically quite fast and can be significantly faster than other O(n log n) algorithms such as HeapSort or MergeSort, because its inner loop can be efficiently implemented on most architectures, and in most real-world data, it is possible to make design choices which minimize the probability of requiring quadratic time.

Programs

```
// C code to implement quicksort

#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

// Partition the array using the last element as the pivot
int partition(int arr[], int low, int high)
{
	// Choosing the pivot
	int pivot = arr[high];

	// Index of smaller element and indicates
	// the right position of pivot found so far
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {

		// If current element is smaller than the pivot
		if (arr[j] < pivot) {

			// Increment index of smaller element
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

// The main function that implements QuickSort
// arr[] --> Array to be sorted,
// low --> Starting index,
// high --> Ending index
void quickSort(int arr[], int low, int high)
{
	if (low < high) {

		// pi is partitioning index, arr[p]
		// is now at right place
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

// Driver code
int main()
{
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	quickSort(arr, 0, N - 1);
	printf("Sorted array: \n");
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	return 0;
}


```

```
// Java implementation of QuickSort
import java.io.*;

class QuickSort {

	// A utility function to swap two elements
	static void swap(int[] arr, int i, int j)
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	// This function takes last element as pivot,
	// places the pivot element at its correct position
	// in sorted array, and places all smaller to left
	// of pivot and all greater elements to right of pivot
	static int partition(int[] arr, int low, int high)
	{
		// Choosing the pivot
		int pivot = arr[high];

		// Index of smaller element and indicates
		// the right position of pivot found so far
		int i = (low - 1);

		for (int j = low; j <= high - 1; j++) {

			// If current element is smaller than the pivot
			if (arr[j] < pivot) {

				// Increment index of smaller element
				i++;
				swap(arr, i, j);
			}
		}
		swap(arr, i + 1, high);
		return (i + 1);
	}

	// The main function that implements QuickSort
	// arr[] --> Array to be sorted,
	// low --> Starting index,
	// high --> Ending index
	static void quickSort(int[] arr, int low, int high)
	{
		if (low < high) {

			// pi is partitioning index, arr[p]
			// is now at right place
			int pi = partition(arr, low, high);

			// Separately sort elements before
			// partition and after partition
			quickSort(arr, low, pi - 1);
			quickSort(arr, pi + 1, high);
		}
	}
	// To print sorted array
	public static void printArr(int[] arr)
	{
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
	}

	// Driver Code
	public static void main(String[] args)
	{
		int[] arr = { 10, 7, 8, 9, 1, 5 };
		int N = arr.length;

		// Function call
		quickSort(arr, 0, N - 1);
		System.out.println("Sorted array:");
		printArr(arr);
	}
}


```


let's go through a step-by-step example of the quicksort algorithm using the array {10, 80, 30, 90, 40, 50, 70}. The steps are as follows:

1.  We start by selecting a pivot. In our example, we'll use the Lomuto partition scheme, which uses the last element in the array as the pivot. So our pivot is 70.
2.  We compare each element in the array with the pivot. If an element is smaller than the pivot, we swap it with the first element that's greater than the pivot.

After the first pass, our array will look like this: {10, 30, 40, 50, 70, 80, 90}. The pivot (70) is now in its final sorted position, and we have two subarrays - one on the left of the pivot, with elements smaller than the pivot, and one on the right, with elements larger.

3.  We recursively apply the same process to the two subarrays. For the left subarray {10, 30, 40, 50}, we choose 50 as our pivot and repeat step 2. This gives us {10, 30, 40, 50} with two subarrays {10, 30, 40} and {}.

Repeating the process on {10, 30, 40}, we select 40 as pivot, giving us {10, 30, 40}, with subarrays {10, 30} and {}.

Finally, we select 30 as the pivot for {10, 30}, giving us {10, 30}, with subarrays {10} and {}.

4.  We follow the same process for the right subarray {80, 90}. Selecting 90 as pivot, we get {80, 90}, with subarrays {80} and {}.

5.  At the end of this process, every element has been placed in its final sorted position, giving us the sorted array {10, 30, 40, 50, 70, 80, 90}.

And that's a step-by-step example of the quicksort algorithm.




