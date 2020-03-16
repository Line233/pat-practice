//https://pintia.cn/problem-sets/994805342720868352/problems/type/7?page=1
//SUMMARY 堆
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
int parent(int k)
{
    return k / 2;
}
bool IsMaxHeap(int *tree, int n)
{
    if (n == 1)
        return 1;
    int k = 1;
    while (k <= n)
    {
        int leftx = left(k);
        int rightx = right(k);
        if (leftx <= n)
        {
            if (tree[k] < tree[leftx])
                return false;
            if (rightx <= n)
                if (tree[k] < tree[rightx])
                    return false;
        }
        k++;
    }
    return true;
}
bool IsMinHeap(int *tree, int n)
{
    if (n == 1)
        return 1;
    int k = 1;
    while (k <= n)
    {
        int leftx = left(k);
        int rightx = right(k);
        if (leftx <= n)
        {
            if (tree[k] > tree[leftx])
                return false;
            if (rightx <= n)
                if (tree[k] > tree[rightx])
                    return false;
        }
        k++;
    }
    return true;
}
void posttraverse(int *tree, int pos, int n)
{
    int leftx = left(pos);
    int rightx = right(pos);
    if (leftx <= n)
        posttraverse(tree, leftx, n);
    if (rightx <= n)
        posttraverse(tree, rightx, n);

    printf("%d", tree[pos]);
    if (pos != 1)
        printf(" ");
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
        int isMax, IsMin;
        isMax = IsMaxHeap(Trees[i], NKeys);
        IsMin = IsMinHeap(Trees[i], NKeys);
        if (isMax)
        {
            printf("Max Heap\n");
        }

        else if (IsMin)
        {
            printf("Min Heap\n");
        }
        else
        {
            printf("Not Heap\n");
        }
        posttraverse(Trees[i], 1, NKeys);
        printf("\n");
    }

    return 0;
}