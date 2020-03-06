// https://pintia.cn/problem-sets/994805342720868352/problems/994805495863296000
#include <iostream>
#include <list>
#include <cmath>

using namespace std;

int main(void)
{
    list<bool> lst;
    while (true)
    {
        int k, d;
        cin >> k;
        if (k < 0)
            break;
        cin >> d;
        lst.push_back(f(k, d));
    }
    list<bool>::iterator i;
    for (i = lst.begin(); i != lst.end(); i++)
    {
        cout << (*i == 1 ? "Yes" : "No") << endl;
    }

    return 0;
}

int reverse(int k, int d)
{
    int sum = 0;
    while (k != 0)
    {
        sum = sum * d + k % d;
        k /= d;
    }
    return sum;
}
bool is_prime(int k)
{
    if (k == 0 || k == 1)
        return false;
    for (int i = 2; i <= sqrt((float)k); i++)
    {
        int m = k % i;
        if (m == 0)
            return false;
    }
    return true;
}
bool f(int k, int d)
{
    if (is_prime(k))
    {
        k = reverse(k, d);
        return is_prime(k);
    }
    else
    {
        return false;
    }
}
