// (Paylaşan: Ihsan)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomValue(int arr[], int n);
void copyArr(int arr[], int arr2[], int n);

void insertionSort(int arr[], int n);
void binaryInsertionSort(int a[], int n);
void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
void shellSort(int arr[], int n);

int t1; // insertion
int t2; // binaryinsertion
int t3; // selection
int t4; // bubble
int t5; // quick
int t6; // shell

void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
        printf("%d-", arr[i]);
}
int main()
{
    int size = 500, tekrar = 5;
    int *dizi = (int *)malloc(sizeof(int) * size);
    int *dizi2 = (int *)malloc(sizeof(int) * size);
    clock_t start, stop;
    srand(time(0));

    for (int i = 0; i < tekrar; i++)
    {
        randomValue(dizi, size);

        copyArr(dizi, dizi2, size);
        start = clock();
        insertionSort(dizi2, size);
        t1 += (int)(clock() - start) * 1000 / CLOCKS_PER_SEC;

        copyArr(dizi, dizi2, size);
        start = clock();
        binaryInsertionSort(dizi2, size);
        t2 += (int)(clock() - start) * 1000 / CLOCKS_PER_SEC;

        copyArr(dizi, dizi2, size);
        start = clock();
        selectionSort(dizi2, size);
        t3 += (int)(clock() - start) * 1000 / CLOCKS_PER_SEC;

        copyArr(dizi, dizi2, size);
        start = clock();
        bubbleSort(dizi2, size);
        t4 += (int)(clock() - start) * 1000 / CLOCKS_PER_SEC;

        copyArr(dizi, dizi2, size);
        start = clock();
        quickSort(dizi2, 0, size);
        t5 += (int)(clock() - start) * 1000 / CLOCKS_PER_SEC;

        copyArr(dizi, dizi2, size);
        start = clock();
        shellSort(dizi2, size);
        t6 += (int)(clock() - start) * 1000 / CLOCKS_PER_SEC;
    }

    printf("\n");
    printf("Insertion sort time:        %dms\n", t1);
    printf("Binary Insertion sort time: %dms\n", t2);
    printf("Selection sort time:        %dms\n", t3);
    printf("Bubble sort time:           %dms\n", t4);
    printf("Quick sort time:            %dms\n", t5);
    printf("Shell sort time:            %dms\n", t6);
    return 0;
}
void copyArr(int arr[], int arr2[], int n)
{
    for (int i = 0; i < n; i++)
        arr2[i] = arr[i];
}
void randomValue(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 9999;
}
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}
//binaryinsertion
int binarySearch(int a[], int item, int low, int high)
{
    if (high <= low)
        return (item > a[low])?  (low + 1): low;

    int mid = (low + high)/2;

    if(item == a[mid])
        return mid+1;

    if(item > a[mid])
        return binarySearch(a, item, mid+1, high);
    return binarySearch(a, item, low, mid-1);
}

// Function to sort an array a[] of size 'n'
void binaryInsertionSort(int a[], int n)
{
    int i, loc, j, k, selected;

    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];

        // find location where selected sould be inseretd
        loc = binarySearch(a, selected, 0, j);

        // Move all elements after location to create space
        while (j >= loc)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = selected;
    }
} // end binary insertion
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// selection
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
// end selection
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
} //end bubble

int partition (int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);

    for (int j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[h]);
    return (i + 1);
}

/* A[] --> Array to be sorted,
  l  --> Starting index,
  h  --> Ending index */
void quickSort(int A[], int l, int h)
{
    if (l < h)
    {
        /* Partitioning index */
        int p = partition(A, l, h);
        quickSort(A, l, p - 1);
        quickSort(A, p + 1, h);
    }
}
void shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return;
}