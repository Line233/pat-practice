#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <array>

using namespace std;

#define ex_n 1001
array<double, ex_n> num1;
array<double, ex_n> num2;
array<double, ex_n> res;

int main()
{
    num1.fill(0);
    num2.fill(0);
    res.fill(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ex;
        double co;
        cin >> ex >> co;
        num1[ex] = co;
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
         int ex;
        double co;
        cin>>ex>>co;
        num2[ex] = co;
    }
    n = 0;
    for (int i = 0; i < ex_n; i++)
    {
        res[i] = num1[i] + num2[i];
        if (res[i] != 0)
            n++;
    }
    cout << n ;
    res=num1+num2;
    for (int i = ex_n-1; i >-1; i--)
    {
        if(res[i]!=0)
        {
            printf(" %d %.1f",i,res[i]);
        }
    }
}