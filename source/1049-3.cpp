//https://pintia.cn/problem-sets/994805342720868352/problems/994805430595731456
//SUMMARY template
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>

using namespace std;

int f1(int k, int i)
{
    int x1, x2;
    x1 = k / (int)pow(10, i + 1);
    x2 = k % (int)pow(10, i);
    int xc = k / (int)pow(10, i) % 10;
    int sum = 0;
    sum += ((x1) * (int)pow(10, i));

    if (xc == 1)
    {
        sum += (x2 + 1);
    }
    else if (xc > 1)
    {

        sum += (int)pow(10, i);
    }
    return sum;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int n2 = n;
    int sum = 0;
    int i = 0;
    while (n2 != 0)
    {
        sum += f1(n, i);
        i++;
        n2 /= 10;
    }
    cout << sum;
    return 0;
}