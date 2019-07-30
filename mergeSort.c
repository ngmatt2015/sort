#include <stdio.h>

int size = 8;
int sorted[8];

void arrPrint(int*);
void merge(int* arr, int m, int middle, int n);
void mergeSort(int *arr, int m, int n);

int main(void)
{
    int arr[] = { 7, 6, 5, 8, 3, 5, 9, 1 };
    arrPrint(arr);
    mergeSort(arr, 0, size - 1);
    arrPrint(arr);
    return 0;
}

void mergeSort(int *arr, int m, int n)
{
    if (m < n)
    {
        int middle = (m + n) / 2;
        mergeSort(arr, m, middle);
        mergeSort(arr, middle + 1, n);
        merge(arr, m, middle, n);
    }
}

void merge(int *arr, int m, int middle, int n)
{
    int i = m;
    int j = middle + 1;
    int k = m;

    while (i <= middle && j <= n)
    {
        if (arr[i] <= arr[j])
        {
            sorted[k] = arr[i];
            i++;
        }
        else
        {
            sorted[k] = arr[j];
            j++;
        }
        k++;
    }
    
    if (i > middle)
    {
        for (int t = j; t <= n; t++)
        {
            sorted[k] = arr[t];
            k++;
        }
    }
    else
    {
        for (int t = i; t <= middle; t++)
        {
            sorted[k] = arr[t];
            k++;
        }
    }

    for (int t = m; t <= n; t++)
        arr[t] = sorted[t];
}

void arrPrint(int *arr)
{
    for (int i = 0; i < 8; i++)
        printf("%3d", arr[i]);
    printf("\n");
}