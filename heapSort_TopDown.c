#include <stdio.h>

#define parent(x) (x-1)/2
#define left_child(x) x*2 +1
#define right_child(x) x*2 + 2

void swap(int*, int*);
void arrPrint(int*);

void heapify(int *arr, int size, int mid);
void heapify_TopDown(int *arr, int size, int child);
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

void heapify_TopDown(int *arr, int size, int child)
{
    int root = parent(child);
    if (arr[root] < arr[child] && root >= 0)
    {
        swap(&arr[root], &arr[child]);
        heapify_TopDown(arr, size, root);
    }
}

void buildMaxHeap(int *arr, int size)
{
    for (int i = 1; i < size; i++)
        heapify_TopDown(arr, size, i);
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