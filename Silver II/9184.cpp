#include <stdio.h>

int w(int a, int b, int c)
{
    if (a <= 0 or b <= 0 or c <= 0)
        return 1;

    if (a > 20 or b > 20 or c > 20)
        return w(20, 20, 20);

    if (a < b and b < c)
        return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);

    return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main()
{
    int a, b, c;
    while (1)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1)
            break;
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
    return 0;
}