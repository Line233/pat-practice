//https://pintia.cn/problem-sets/994805342720868352/problems/994805430595731456
//SUMMARY template
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int num[30];
long long f1(long long k)
{
    long long sum = 0;
    while (k > 0)
    {
        if (k % 10 == 1)
            sum++;
        k /= 10;
    }
    return sum;
}
int main(void)
{
    fill(num,num+30,-1);
    long long n;
    cin >> n;
    long long sum = 0;
    for (long long i = 1; i <= n; i++)
    {
        sum += f1(i);
    }
    cout << sum;
    return 0;
}