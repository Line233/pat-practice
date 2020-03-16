//https://pintia.cn/problem-sets/994805342720868352/problems/type/7?page=1
//SUMMARY 堆 树的后序非递归遍历
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

const int MaxTrees = 100;
const int MaxKeys = 1001;
int Trees[MaxTrees][MaxKeys];
vector<int> MaxHeap;
vector<int> MinHeap;
vector<int> NotHeap;

int NTrees;
int NKeys;

int left(int k)
{
    return k * 2;
}
int right(int k)
{
    return left(k) + 1;
}

int HeapType(int *tree, int n)
{
    if (n == 1)
        return 1;
    int res = 0;
    int k = 1;
    while (k <= n / 2)
    {
        int child = left(k);
        for (int i = child; i < child + 2 && child <= n; i++)
        {
            int sub = (tree[k] - tree[child]);
            if (res == 0)
                res = sub;
            else if (res * sub < 0)
                return 0;
        }
        k++;
    }
    return res > 0 ? 1 : -1;
}
void posttraverse(int *tree, int pos, int n)
{
    vector<int> nodes;
    nodes.push_back(1);
    int pre = -1;
    while (!nodes.empty())
    {
        int work = nodes.back();
        if (work == 0)
        {
            nodes.pop_back();
            pre = work;
            continue;
        }
        int rightx = right(work) <= n ? right(work) : 0;
        int leftx = left(work) <= n ? left(work) : 0;
        if (pre == rightx)
        {
            printf("%d", tree[work]);
            if (work != 1)
                printf(" ");
            nodes.pop_back();
            pre = work;
        }
        else
        {
            nodes.push_back(rightx);
            nodes.push_back(leftx);
        }
    }
}
int main(void)
{
    scanf("%d %d", &NTrees, &NKeys);
    for (int i = 0; i < NTrees; i++)
    {
        for (int j = 1; j <= NKeys; j++)
        {
            int input;
            scanf("%d", &input);
            Trees[i][j] = input;
        }
        int heaptype;
        heaptype = HeapType(Trees[i], NKeys);
        switch (heaptype)
        {
        case 1:
            printf("Max Heap\n");
            break;
        case -1:
            printf("Min Heap\n");
            break;
        default:
            printf("Not Heap\n");
            break;
        }
        posttraverse(Trees[i], 1, NKeys);
        printf("\n");
    }

    return 0;
}