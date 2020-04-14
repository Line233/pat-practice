//https://pintia.cn/problem-sets/994805342720868352/problems/994805417945710592
/*SUMMARY 
    栈
    树形数组
    //树形数组用于查找前kth个数（可以用于中位数
*/
//TODO fix bug
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

vector<int> Stack;
const int MaxIndex = 131072; //2的幂，用于建树
vector<int> Hash(MaxIndex + 1);
vector<int> Tree(MaxIndex + 1);
const string pop = "Pop";
const string push = "Push";
const string pm = "PeekMedian";

int lowbit(int k)
{
    return k & (-k);
}
void sub(int k)
{
    Hash[k]--;
    while (k <= MaxIndex)
    {
        Tree[k]--;
        k += lowbit(k); //向上查找
    }
}
void add(int k)
{
    Hash[k]++;
    while (k <= MaxIndex)
    {
        Tree[k]++;
        k += lowbit(k);
    }
}
//方法1：树：从上往下查找
int findnum(int node, int kth)
{
    if (Tree[node] < kth)
        exit(-1);
    int sub = lowbit(node) / 2;
    int high = 0;
    int low = 0;
    while (sub > 0) //查找所有儿子
    {
        high += Tree[node - sub];
        if (high >= kth)
            return findnum(node - sub, kth - low);
        sub /= 2;
        low = high;
    }
    //sub==0 leaf
    return node;
}
//方法二：二分查找
int getsum(int k) //求前缀和
{
    int sum = 0;
    while (k > 0)
    {
        sum += Tree[k];
        k -= lowbit(k);
    }
    return sum;
}
int findnum(int low, int high, int kth) //meian
{
    if (high <= low)
        return low;
    int m = (high + low) / 2;
    int sum = getsum(m);
    if (sum >= kth)
        return findnum(low, m, kth);
    else
        return findnum(m+1, high, kth);
}

int main(void)
{
    fill(Hash.begin(), Hash.end(), 0);
    fill(Tree.begin(), Tree.end(), 0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string op;
        cin >> op;
        if (op == pop)
        {
            if (Stack.size() != 0)
            {
                int k = Stack.back();
                cout << k << endl;
                Stack.pop_back();
                sub(k);
            }
            else
                cout << "Invalid" << endl;
        }
        else if (op == push)
        {
            int k;
            cin >> k;
            Stack.push_back(k);
            add(k);
        }
        else //median
        {
            if (Stack.size() != 0)
            {
                int k = findnum(1, MaxIndex, (Stack.size() + 1) / 2);
                cout << k << endl;
            }
            else
                cout << "Invalid" << endl;
        }
    }
    return 0;
}