#include <stdio.h>

void swap(int*, int*);
void arrPrint(int*);

int main(void)
{
    int arr[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
    int i, j, min, index;
    arrPrint(arr);

    for (i = 0; i < 10; i++) {
        min = arr[i];
        index = i;
        for (j = i; j < 10; j++) {
            if (min > arr[j]) {
                min = arr[j];
                index = j;
            }
        }
        swap(&arr[i], &arr[index]);
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