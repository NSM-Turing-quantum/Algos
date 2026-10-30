#include <stdio.h>
#include <math.h>

int mySqrt(int n)
{
    if (n < 0)
        return -1;
    if (n == 0 || n == 1)
        return n;

    int left = 1;
    int right = n;
    int my_sqrt = 0;

    int mid;
    long long mid_2;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        mid_2 = (long long)mid * mid;

        if (mid_2 == n)
        {
            return mid;
        }
        else if (mid_2 < n)
        {
            my_sqrt = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return my_sqrt;
}

int main()
{
    int test_cases[] = {0, 1, 3, 4, 8, 12, 17, 764378, 83212342, 198398875};
    int i;

    for (i = 0; i < 10; i++)
    {
        printf("sqrt(%d) ~ %d  // (%lf)\n", test_cases[i], mySqrt(test_cases[i]), sqrt(test_cases[i]));
    }

    return 0;
}
