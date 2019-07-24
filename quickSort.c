#include <stdio.h>

void swap(int*, int*);
void arrPrint(int*);
void quickSort(int*, int, int);

int main(void)
{
    int length = 10;
    int arr[] = { 1, 5, 8, 7, 6, 4, 3, 2, 9, 10 };
    arrPrint(arr);
    quickSort(arr, 0, length - 1);
    arrPrint(arr);
}

void quickSort(int *arr, int start, int end)
{
    if (start >= end) return;

    int pivot = arr[start];
    int low = start + 1;
    int high = end;

    while (low <= high)
    {
        while (low <= end && arr[low] <= pivot)
            low++;
        while (high >= start + 1 && arr[high] >= pivot)
            high--;
        if (low <= high)
            swap(&arr[low], &arr[high]);
    }
    swap(&arr[start], &arr[high]);

    quickSort(arr, start, high - 1);
    quickSort(arr, high + 1, end);
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void arrPrint(int *arr)
{
    for (int i = 0; i < 10; i++)
        printf("%3d", arr[i]);
    printf("\n");
}