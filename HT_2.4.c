#include <stdio.h>

char Orig(char* a, char* b)
{
    if (*a == '\0')
    {
        return 'y';
    }

    char* A_ = a;
    char* B_ = b;

    while (*B_ != '\0')
    {
        if (*A_ == *B_)
        {
            A_++;

            if (*A_ == '\0')
            {
                return 'y';
            }
        }

        B_++;
    }

    return 'n';
}

int main()
{
    char* a = "abc";
    char* b = "1a2bz3c";
    printf("a:  %s, b:  %s, result:  %c\n", a, b, Orig(a, b));

    a = "abc";
    b = "bacb";
    printf("a:  %s, b:  %s, result:  %c\n", a, b, Orig(a, b));

    a = "abcd";
    b = "abc";
    printf("a:  %s, b:  %s, result:  %c\n", a, b, Orig(a, b));

    return 0;
}
