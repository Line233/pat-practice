//https://pintia.cn/problem-sets/994805342720868352/problems/994805402305150976
/*SUMMARY 
    动态规划问题,背包问题
    或者也可以深度/广度遍历（性能不好）
*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <stdio.h>
#include <map>

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
vector<int> MaxC;
map<pair<int, int>, int> Path;
int Sum = 0;
int Money;

int main(void)
{
    int n;
    cin >> n >> Money;
    MaxC.resize(Money + 1);
    fill(MaxC.begin(), MaxC.end(), 0);
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        Coins.push_back(k);
    }
    sort(Coins.rbegin(), Coins.rend()); //升序
    /*
    迭代，选前i个硬币时，最大容量为j时，能够到达的容量
    */
    for (int i = 0; i < Coins.size(); i++)
    {
        for (int j = Money; j >= Coins[i]; j--)
        {
            if (MaxC[j] <= MaxC[j - Coins[i]] + Coins[i])
            {

                MaxC[j] = MaxC[j - Coins[i]] + Coins[i];
                Path[{i, j}] = 1;
            }
        }
    }

    if (MaxC[Money] != Money)
        cout << "No Solution";
    else
    {
        vector<int> p;
        for (int i = Coins.size() - 1; i >= 0 && Money != 0; i--)
        {
            if (Path.count({i, Money}) != 0)
            {
                p.push_back(Coins[i]);
                Money -= Coins[i];
            }
        }
        for (auto ite = p.begin(); ite != p.end(); ite++)
            cout << *ite << ((ite == p.end() - 1) ? "" : " ");
    }
    return 0;
}
