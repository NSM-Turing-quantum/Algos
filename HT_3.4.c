#include <stdio.h>

char aXORb(char *a, char *b)
{
    char res = NULL;

    for (int i = 0; a[i] != '\0'; i++)
    {
        res ^= a[i];
    }

    for (int i = 0; b[i] != '\0'; i++)
    {
        res ^= b[i];
    }

    return res;
}

int main()
{
    char *a = "abcd";
    char *b = "cadbf";

    printf("a (XOR) b: %c\n", aXORb(a, b));

    return 0;
}
