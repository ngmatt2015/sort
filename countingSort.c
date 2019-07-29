#include <stdio.h>

int main(void)
{
    int count[6];
    int arr[] = { 1, 3, 4, 3, 2, 5, 4, 2, 1, 3,
        1, 3, 4, 3, 2, 5, 4, 2, 1, 3,
        1, 3, 4, 3, 2, 5, 4, 2, 1, 3 };

    for (int i = 1; i < 6; i++)
        count[i] = 0;
    for (int i = 0; i < 30; i++)
        count[arr[i]]++;
    for (int i = 1; i < 6; i++)
    {
        if (count[i] != 0)
        {
            for (int j = 0; j < count[i]; j++)
                printf("%3d", i);
        }
    }
    printf("\n");
    return 0;
}