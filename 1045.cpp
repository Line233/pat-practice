// https://pintia.cn/problem-sets/994805342720868352/problems/994805437411475456

#include <iostream>
#include <array>
#include<algorithm>
using namespace std;

int find_max_index(int *lis, int n, int end)
{
    if (end >= n)
        exit(1);
    int max = 0;
    for (int i = 0; i <= end; i++)
    {
        if (lis[i] > lis[max])
        {
            max = i;
        }
    }
    return max;
}

int main(void)
{
    int n, m, k;
    //
    cin >> n;
    int *hash = (int *)malloc(sizeof(int) * (n + 1));
    fill(hash,hash+n+1,-1);
    //
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        hash[num] = i;
    }
    //
    cin >> k;
    int *score = (int *)malloc(sizeof(int) * m);
    fill(score,score+m,0);
    for (int i = 0; i < k; i++)
    {
        int num;
        cin >> num;
        num = hash[num];
        if (num != -1)
        {
            int max = find_max_index(score, m, num);
            score[num] = score[max] + 1;
        }
    }
    cout << score[find_max_index(score, m, m - 1)];
    return 0;
}