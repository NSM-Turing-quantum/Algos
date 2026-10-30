#include <stdio.h>

void sortArray(int arr[], int size)
{
    int temp;
    int i, j;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int Fed(int an[], int num_an, int port[], int num_port)
{
    sortArray(an, num_an);
    sortArray(port, num_port);

    int counter = 0;
    int i = 0, j = 0;

    while (i < num_an && j < num_port)
    {
        if (an[i] <= port[j])
        {
            counter++;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }

    return counter;
}

int main()
{
    int an_1[] = {3, 1, 4, 2, 5};
    int num_an_1 = 5;

    int port_1[] = {2, 1, 3, 1, 5, 2};
    int num_port_1 = 6;

    printf("Fed pets: %d\n", Fed(an_1, num_an_1, port_1, num_port_1));

    int an_2[] = {6, 8, 13, 24, 1, 1, 1, 3, 5};
    int num_an_2 = 9;

    int port_2[] = {2, 1, 3, 1, 5, 2, 13, 1, 4};
    int num_port_2 = 9;

    printf("Fed pets: %d\n", Fed(an_2, num_an_2, port_2, num_port_2));


    return 0;
}
