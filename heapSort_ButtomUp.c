#include <stdio.h>

void swap(int*, int*);
void arrPrint(int*);

void heapify(int *arr, int size, int mid);
void buildMaxHeap(int *arr, int size);
void heapSort(int *arr, int size);

int main(void)
{
    int size = 10;
    int arr[] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
    arrPrint(arr);
    heapSort(arr, size);
    arrPrint(arr);
    return 0;
}

void heapify(int *arr, int size, int mid)
{
    int parent_node = mid;
    int left_child = parent_node * 2 + 1;
    int right_child = parent_node * 2 + 2;
    int largest_node = parent_node;

    if (left_child < size && arr[left_child] > arr[largest_node])
        largest_node = left_child;
    if (right_child < size && arr[right_child] > arr[largest_node])
        largest_node = right_child;
    if (parent_node != largest_node)
    {
        swap(&arr[largest_node], &arr[parent_node]);
        heapify(arr, size, largest_node);
    }
}

void buildMaxHeap(int *arr, int size)
{
    int mid = size / 2 - 1;
    for (mid; mid >= 0; mid--)
        heapify(arr, size, mid);
}

void heapSort(int *arr, int size)
{
    buildMaxHeap(arr, size);
    while (size > 1)
    {
        swap(&arr[0], &arr[size - 1]);
        size--;
        heapify(arr, size, 0);
    }
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