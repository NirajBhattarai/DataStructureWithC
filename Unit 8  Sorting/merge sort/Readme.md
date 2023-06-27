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

Merge Array Half Sorted

```
// Online C compiler to run C program online
#include <stdio.h>

void sort(int arr[],int low,int mid,int last)
{
    int i,j,k;
    int n1 =4;
    int n2 =4;
    
    // temp Array
    int left[n1];
    int right[n2];
    
    for(i =0;i<n1;i++)
    {
        left[i]= arr[i];
    }
    for(j =0;j<n2;k++)
    {
        right[j]= arr[mid+1+j];
    }
    
    // reset i j k to intial value
     i =0;
     j=0;
     k =0;
     while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
            i++;
        } else {
            arr[k++] = right[j++];
        }
    }
    
     // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k++] = left[i++];
    }
  
    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k++] = right[j++];
    }
     
    
}

int main() {
    int arr[] = {1,3,5,7,2,4,6,8};
    
    int low =0;
    int mid = 3;
    int last = 7;
    
    printf("Original Array:\n");
    for(int i =0;i<8;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
    sort(arr,low,mid,last);
    
    printf("Array after merging:\n");
    for (int i = 0; i < 4; i++)
        printf("%d ", arr[i]);

    return 0;
}

```

```
#include <stdio.h>

void sort(int arr[], int low, int mid, int last) {
    int i, j, k;
    int n1 = 4;
    int n2 = 4;
  
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
    int mid = 3; // mid is the last index of the first sorted sub-array
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

# Iterative Merge Sort

Merge Sort is a popular comparison-based sorting algorithm that works on the principle of the divide-and-conquer programming approach. It works by recursively splitting an array into two equal halves, sorting them separately, and finally merging them in sorted order.

However, the Iterative Merge Sort does not involve recursion. Instead, it performs iterative division of the array for sorting.


## How it works
The Iterative Merge Sort technique performs the following steps:

If it is only one element in the list, it is already sorted. Return.
Divide the unsorted list into n sublists, each containing one element.
Repeatedly merge sublists to produce new sorted sublists until there is only one sublist remaining.

## Time Complexity

```

#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0;
    j = 0;
    k = l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int n) {
    int p;
    for (p=2; p<=n; p=p*2){
        for (int i=0; i+p-1<n; i=i+p){
            int low = i;
            int high = i+p-1;
            int mid = (low+high)/2;
            merge(arr, low, mid, high);
        }
    }
    if (p/2 < n){
        merge(arr, 0, p/2-1, n-1);
    }
}
 
void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, n);
    printf("\n");
 
    mergeSort(arr, n);
 
    printf("\nSorted array is \n");
    printArray(arr, n);
    return 0;
}

```

## Program in Java

```
public class MergeSort {
    void merge(int arr[], int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        int L[] = new int[n1];
        int R[] = new int[n2];

        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];

        int i = 0, j = 0;

        int k = l;
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

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSort(int arr[], int n) {
        int p;
        for (p = 2; p <= n; p = p * 2) {
            for (int i = 0; i + p - 1 < n; i = i + p) {
                int low = i;
                int high = i + p - 1;
                int mid = (low + high) / 2;
                merge(arr, low, mid, high);
            }
        }
        if (p / 2 < n) {
            merge(arr, 0, p / 2 - 1, n - 1);
        }
    }

    static void printArray(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    public static void main(String args[]) {
        int arr[] = {12, 11, 13, 5, 6, 7};

        System.out.println("Given Array");
        printArray(arr);

        MergeSort ob = new MergeSort();
        ob.mergeSort(arr, arr.length);

        System.out.println("\nSorted array");
        printArray(arr);
    }
}

```
## Example 

Assume we have the following array:

arr = [38, 27, 43, 3, 9, 82, 10]

An iterative merge sort would sort the array as follows:

Iteration 1: Treat each element as a sorted sublist:

[38], [27], [43], [3], [9], [82], [10]

Iteration 2: Merge adjacent sublists:

[27, 38], [3, 43], [9, 82], [10]

Iteration 3: Continue merging adjacent sublists:

[3, 27, 38, 43], [9, 10, 82]

Iteration 4: Merge the remaining sublists:

[3, 9, 10, 27, 38, 43, 82]

At the end of this process, we have a fully sorted array.