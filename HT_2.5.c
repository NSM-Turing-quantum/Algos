#include <stdio.h>

int target_sum(int arr[], int size, int target)
{
    int left = 0, right = size - 1, sum;

    while (left < right)
    {
        sum = arr[left] + arr[right];

        if (sum == target)
        {
            printf("Pair for target %d is %d, %d\n",  target, arr[left], arr[right]);
            return 1;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    printf("No target sum\n");
    return 0;
}

int main()
{
    int target = 10, size = 5;

    int arr1[] = {1, 2, 3, 4, 5};
    target_sum(arr1, size, target);

    printf("\n");

    int arr2[] = {1, 2, 3, 4, 6};
    target_sum(arr2, size, target);

    return 0;
}
