/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    va_list args;
    va_start(args, __format);
    vprintf(__format, args);
    va_end(args);
#endif
}

double d1, d2;

signed main()
{
    scanf("%lf %lf", &d1, &d2);
    printf("%lf", d1 * 2 + d2 * 2 * 3.141592);
    return 0;
}