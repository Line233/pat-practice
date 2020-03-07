// https://pintia.cn/problem-sets/994805342720868352/problems/994805460652113920
#include <iostream>
#include <algorithm>
#include <array>
#include <iomanip>
using namespace std;

#define N_max 100000

array<int, N_max> nums;
array<int, N_max> tokens;

int start1;
int start2;

int main(void)
{
    nums.fill(-1);
    tokens.fill(0);

    cin >> start1 >> start2;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s, next;
        char k;
        cin >> s >> k >> next;
        nums[s] = next;
    }
    while (start1 != -1)
    {
        tokens[start1] = 1;
        start1 = nums[start1];
    }
    while (start2 != -1 && tokens[start2] != 1)
    {
        start2 = nums[start2];
    }
    if (start2 == -1)
        cout << -1;
    else
    {

        array<int, 5> print;
        for (int i = 0; i < 5; i++)
        {
            print[i] = start2 % 10;
            start2 /= 10;
        }
        for (int i = 4; i >= 0; i--)
        {
            cout << print[i];
        }
    }
    return 0;
}