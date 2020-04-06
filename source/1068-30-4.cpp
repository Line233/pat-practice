//https://pintia.cn/problem-sets/994805342720868352/problems/994805402305150976
/*SUMMARY 
    动态规划问题
    或者也可以深度/广度遍历（性能不好）
*/
//TODO fix bug ,动态规划
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <stdio.h>

using namespace std;

vector<int> Coins;
typedef struct node
{
    struct node *parent;
    int coin;
    vector<struct node *> sub;
} Node;
// vector<int> Path;
vector<int> Indexes;
int Sum = 0;
int Money;
bool dfs(int index)
{
    int last;
    if (index == 0)
        last = -1;
    else
        last = Indexes[index - 1];
    for (int i = last + 1; i < Coins.size(); i++)
    {
        if (Sum + Coins[i] == Money)
        {
            Indexes.push_back(i);
            return true;
        }
        else if (Sum + Coins[i] < Money)
        {
            Sum += Coins[i];
            Indexes.push_back(i);
            if (dfs(index + 1))
                return true;
            else
            {
                Sum -= Coins[i];
                Indexes.pop_back();
            }
        }
        else //>Money
            return false;
    }
    return false;
}
bool bfs(int index)
{
    int last, maxindex;
    if (index == 0)
        last = -1;
    else
        last = Indexes[index - 1];
    for (int i = last + 1; i < Coins.size(); i++)
    {
        if (Sum + Coins[i] > Money)
        {
            maxindex = i;
            break;
        }
    }
    for (int i = last + 1; i < maxindex; i++)
    {
        if (Sum + Coins[i] == Money)
        {
            Indexes.push_back(i);
            return true;
        }
        if (Sum + Coins[i] < Money)
        {
            Indexes.push_back(i);
            Sum += Coins[i];
            if (bfs(index + 1))
                return true;
            else
            {
                Sum -= Coins[i];
                Indexes.pop_back();
            }
        }
        else if (Sum + Coins[i] > Money)
        {
            return false;
        }
    }
    return false;
}

int main(void)
{
    int n;
    cin >> n >> Money;
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        Coins.push_back(k);
    }
    sort(Coins.begin(), Coins.end());
    if (bfs(0))
    {
        for (int i = 0; i < Indexes.size(); i++)
        {
            cout << Coins[Indexes[i]] << (i == Indexes.size() - 1 ? "" : " ");
        }
    }
    else
        cout << "No Solution";
    return 0;
}