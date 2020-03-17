//https://pintia.cn/problem-sets/994805342720868352/problems/1038430130011897856
//SUMMARY 树，正序与前序序列确定一棵树
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

const int MaxKeys = 10000;
int NKeys;

int inorder[MaxKeys];
int preorder[MaxKeys];
int sub[MaxKeys][3];
bool read[MaxKeys];

int GetTree(int begin, int end, int begin_in, int end_in, int parent)
{
    sub[begin][2] = parent;
    if (begin == end - 1)
    {
        sub[begin][0] = -1;
        sub[begin][1] = -1;
        return begin;
    }
    int center = preorder[begin];
    int s = begin_in;
    while (inorder[s] != center)
    {
        s++;
    }
    int lcount = s - begin_in;
    int rcount = end_in - s - 1;
    if (lcount != 0)
        sub[begin][0] = GetTree(begin + 1, begin + 1 + lcount, begin_in, s, begin);
    if (rcount != 0)
        sub[begin][1] = GetTree(begin + 1 + lcount, end, s + 1, end_in, begin);
    return begin;
}
int find(int k)
{
    int i = 0;
    while (i < NKeys && preorder[i] != k)
    {
        i++;
    }
    return i == NKeys ? -1 : i;
}
int upgo(int pos)
{
    if (pos == -1)
        return 0;
    else if (read[pos])
        return pos;
    read[pos] = true;
    return upgo(sub[pos][2]);
}

int main(void)
{
    int mpairs;
    scanf("%d %d", &mpairs, &NKeys);
    for (int i = 0; i < NKeys; i++)
    {
        int input;
        scanf("%d", &input);
        inorder[i] = input;
    }
    for (int i = 0; i < NKeys; i++)
    {
        int input;
        scanf("%d", &input);
        preorder[i] = input;
    }
    GetTree(0, NKeys, 0, NKeys, -1);
    for (int i = 0; i < mpairs; i++)
    {
        fill(read, read + NKeys, false);

        int ina, inb;
        scanf("%d %d", &ina, &inb);
        int posa = find(ina);
        int posb = find(inb);
        if (posa != -1 && posb != -1)
        {
            int resa = upgo(posa);
            int resb = upgo(posb);
            if (resb == posb || resb == posa)
            {
                int child = (resb == posb ? posa : posb);
                printf("%d is an ancestor of %d.", preorder[resb], preorder[child]);
            }
            else
            {
                printf("LCA of %d and %d is %d.", ina, inb, preorder[resb]);
            }
        }
        else if (posa == -1 && posb == -1)
        {
            printf("ERROR: %d and %d are not found.", ina, inb);
        }
        else
        {
            int error = (posa == -1 ? ina : inb);
            printf("ERROR: %d is not found.", error);
        }
        printf("\n");
    }
    return 0;
}