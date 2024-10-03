#ifndef _FAST_READ_FAST_WRITE_
#define _FAST_READ_FAST_WRITE_
#define _CRT_SECURE_NO_WARNINGS // Visual Studio
#include <stdio.h>

char buf[1 << 20], *p1, *p2;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++)
inline void read(int &x)
{
    register int f = 1;
    register char ch = getchar();
    x ^= x;
    while (ch < 48 || ch > 57)
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch > 47 && ch < 58)
        x = x * 10 + (ch ^ 48), ch = getchar();
    x *= f;
}
char obuf[1 << 20], *p3 = obuf;
#define putchar(x) (p3 - obuf < 1 << 20) ? (*p3++ = x) : (fwrite(obuf, p3 - obuf, 1, stdout), p3 = obuf, *p3++ = x)
inline void write(int &x)
{
    if (!x)
    {
        putchar('0');
        return;
    }
    static int c[20];
    register int len{}, k1{x};
    if (k1 < 0)
        k1 = -k1, putchar('-');
    while (k1)
        c[len++] = k1 % 10 ^ 48, k1 /= 10;
    while (len--)
        putchar(c[len]);
}
struct _FAST_
{
    ~_FAST_()
    {
        fwrite(obuf, p3 - obuf, 1, stdout);
    }
} _fast_;
#endif
