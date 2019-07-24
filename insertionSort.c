#include <stdio.h>

void swap(int*, int*);
void arrPrint(int*);

int main(void)
{
    int i, j, temp;
    int arr[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
    arrPrint(arr);

    for (i = 0; i < 9; i++)
    {
        j = i;
        while (j >= 0 && arr[j] > arr[j + 1])
        {
            swap(&arr[j], &arr[j + 1]);
            j--;
        }
    }

    arrPrint(arr);
    return 0;
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