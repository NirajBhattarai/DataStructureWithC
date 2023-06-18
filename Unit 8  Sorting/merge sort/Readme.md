# Merge Two Sorted Arrays in C

```

#include <stdio.h>

void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;

    // Traverse both arrays
    while (i<n1 && j <n2)
    {
        // Check if current element of first array is smaller than current element of second array. 
        // If yes, store first array element and increment first array index. Otherwise do same with second array
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    // Store remaining elements of first array
    while (i < n1)
        arr3[k++] = arr1[i++];

    // Store remaining elements of second array
    while (j < n2)
        arr3[k++] = arr2[j++];
}

int main()
{
    int arr1[] = {1, 3, 5, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 4, 6, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[n1+n2];
    mergeArrays(arr1, arr2, n1, n2, arr3);

    printf("Array after merging\n");
    for (int i=0; i < n1+n2; i++)
        printf("%d ", arr3[i]);

    return 0;
}

```

```
#include <stdio.h>

void sort(int arr[], int low, int mid, int last) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = last - mid;
  
    // Create temp arrays
    int L[n1], R[n2];
  
    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
  
    // Merge the temp arrays back into arr[low..last]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = low; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 2, 4, 6, 8};
    int array_size = sizeof(arr) / sizeof(arr[0]);
  
    int low = 0;
    int mid = array_size / 2 - 1; // mid is the last index of the first sorted sub-array
    int last = array_size - 1;

    printf("Original array:\n");
    for (int i = 0; i < array_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    sort(arr, low, mid, last);

    printf("Array after merging:\n");
    for (int i = 0; i < array_size; i++)
        printf("%d ", arr[i]);
  
    return 0;
}
```