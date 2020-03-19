//https://pintia.cn/problem-sets/994805342720868352/problems/1071785408849047552
//SUMMARY 堆 判断大根 小根 还可以用深度遍历
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int NKeys;

vector<int> Tree;

int print2(int k)
{
    int res = 0;
    bool isHeap = true;
    vector<int> out;
    out.push_back(Tree[k]);
    int pre = k;
    k /= 2;

    while (k >= 1)
    {
        int sub = Tree[k] - Tree[pre];
        if (res == 0 && sub != 0)
            res = sub > 0 ? 1 : -1;
        if (res * sub < 0)
            isHeap = false;
        out.push_back(Tree[k]);
        pre = k;
        k /= 2;
    }
    for (int i = out.size() - 1; i >= 0; i--)
    {
        printf("%d", out[i]);
        if (i != 0)
            printf(" ");
    }
    printf("\n");
    return isHeap ? res : -2;
}
void read()
{
    scanf("%d", &NKeys);
    Tree.push_back(-1);
    for (int i = 0; i < NKeys; i++)
    {
        int in;
        scanf("%d", &in);
        Tree.push_back(in);
    }
}
void compute(map<int, int> &isheap)
{
    int firstlevel = 1, secondlevel;
    secondlevel = NKeys;
    int co = 1;
    while (firstlevel < NKeys)
    {
        firstlevel += pow(2, co);
        co++;
    }
    firstlevel -= pow(2, co - 1);

    int index1 = firstlevel;
    while (index1 * 2 > NKeys)
    {
        int k = print2(index1);
        isheap[k]++;
        index1--;
    }
    while (secondlevel > firstlevel)
    {
        int k = print2(secondlevel);
        isheap[k]++;
        secondlevel--;
    }
}
int main(void)
{

    read();
    map<int, int> isheap;
    compute(isheap);
    if (isheap[-2] != 0 || (isheap[1] != 0 && isheap[-1] != 0))
        printf("Not Heap");
    else if (isheap[1] != 0)
        printf("Max Heap");
    else
        printf("Min Heap");

    return 0;
}