#include <stdio.h>

long long MinTime(long long N, long long x, long long y)
{

    if (N == 0)
        return 0;

    long long left = 0, right, mid, ans, copies;

    if (x > y)
        right = N * x;
    else
        right = N * y;

    ans = right;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        copies = (mid / x) + (mid / y);

        if (copies >= N)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return ans;
}

int main()
{
    printf("Min time for %lld copies: %lld minutes if x: %lld   y: %lld\n", 10, MinTime(10, 2, 5), 2, 5);
    printf("Min time for %lld copies: %lld minutes if x: %lld   y: %lld\n", 15, MinTime(15, 8, 6), 8, 6);

    return 0;
}
