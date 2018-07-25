#include <cstdio>
#include <cmath>
int main()
{
    int T, h, m; double z; char ch;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d UTC%c%lf", &h, &m, &ch, &z);
        if (ch == '-')
            z = -z;
        z -= 8.0;
        m += round(z * 60);
        while (m < 0)
        {
            --h;
            m += 60;
        }
        while (m >= 60)
        {
            ++h;
            m -= 60;
        }
        if (h < 0)
            h += 24;
        if (h >= 24)
            h -= 24;
        if (h < 10)
            printf("0%d", h);
        else
            printf("%d", h);
        printf(":");
        if (m < 10)
            printf("0%d", m);
        else
            printf("%d", m);
        puts("");
    }
} 