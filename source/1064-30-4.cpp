//https://pintia.cn/problem-sets/994805342720868352/problems/994805407749357568
/*SUMMARY 
    二叉搜索树
    完全二叉树中序序列生成层序数列
*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;
vector<int> Nums;
vector<int> leveltree;
deque<pair<int, int>> Trees;

int getsize(int h)
{
    return pow(2, h) - 1;
}
int findcenter(pair<int, int> tree)
{
    int n = tree.second - tree.first;
    int h = log2(n + 1);
    int left;
    if (n == getsize(h)) //full binary tree
    {
        left = (n - 1) / 2;
    }
    else
    {
        if (n < 1 + getsize(h) + getsize(h - 1))
            left = n - 1 - getsize(h - 1);
        else
            left = getsize(h);
    }
    return tree.first + left;
}

int main(void)
{
    int nnodes;
    cin >> nnodes;
    for (int i = 0; i < nnodes; i++)
    {
        int k;
        cin >> k;
        Nums.push_back(k);
    }
    sort(Nums.begin(), Nums.end()); //center first

    Trees.push_back({0, nnodes});
    while (Trees.size() != 0)
    {
        pair<int, int> p = Trees.front();
        Trees.pop_front();
        int c = findcenter(p);
        leveltree.push_back(Nums[c]);
        if (p.first != c)
            Trees.push_back({p.first, c});
        if (p.second != c + 1)
            Trees.push_back({c + 1, p.second});
    }
    for (int i = 0; i < leveltree.size(); i++)
    {
        cout << leveltree[i] << ((i == leveltree.size() - 1) ? "" : " ");
    }
    return 0;
}