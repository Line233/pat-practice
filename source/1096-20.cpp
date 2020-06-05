// website
/*SUMMARY 
    template
*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

int N;
int findfactor(int k)
{
    if (k <= 1)
        return 1;
    int f = 2;
    while (k % f != 0)
    {
        f++;
    }
    return f;
}

int main(void)
{
    vector<int> result;
    vector<int> factors;
    cin >> N;
    while (N != 1)
    {
        int f = findfactor(N);
        if (factors.size() == 0 || f == (*(factors.end()) + 1))
        {
            factors.push_back(f);
        }
        else
        {
            if (result.size() < factors.size())
            {
                result.clear();
                result.insert(result.begin(), factors.begin(), factors.end());
            }
            factors.clear();
        }
        N /= f;
    }
    if (result.size() < factors.size())
    {
        result.clear();
        result.insert(result.begin(), factors.begin(), factors.end());
    }
    cout << result.size() << endl;
    for (auto ite = result.begin(); ite != result.end(); ite++)
    {
        cout << *ite << (ite == result.end() - 1) ? "" : " ";
    }
    return 0;
}