#include <stdio.h>
#include <iostream>
using namespace std;
long long gethash(char *c, int n)
{
    int res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        res += c[i];
        res *= 256;
    }
    res += c[n - 1];
    return res;
}
void dehash(int k, char *c, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        c[i] = k % 256;
        k /= 256;
    }
}
int main()
{
    char c[6] = "hello";
    int k = gethash(c, 6);
    dehash(k, c, 6);
    cout << c;
}
