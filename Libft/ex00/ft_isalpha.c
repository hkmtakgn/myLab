#include <stdio.h>

void ft_isalpha (void)
{
    char a = 'H';
    if ((a >= 'A' && a<= 'Z') || (a >= 'a' && a <= 'z'))
    {
        putchar ('T');
    }
    else
    {
        putchar ('F');
    }
}
