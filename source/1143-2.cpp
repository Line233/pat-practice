// https://pintia.cn/problem-sets/994805342720868352/problems/994805343727501312
//SUMMARY 树
#include <stdio.h>
#include <algorithm>

using namespace std;

const int max_keys = 10000;
int tree[max_keys];
int rela[max_keys][3];
bool read[max_keys];
int N_keys = 0;
int read_iteraly(int k, int pos)
{
    read[pos] = true;
    if (tree[pos] == k)
        return 1;
    if (k < tree[pos])
    {
        if (rela[pos][0] != -1)
            return read_iteraly(k, rela[pos][0]);
        else
            return -1;
    }
    else
    {
        if (rela[pos][1] != -1)
            return read_iteraly(k, rela[pos][1]);
        else
            return -1;
    }
}
int read_key(int k)
{
    fill(read, read + max_keys, false);
    return read_iteraly(k, 0);
}

int up_find(int pos)
{
    while (read[pos] != true && rela[pos][2] != -2)
    {
        pos = rela[pos][2];
    }
    return tree[pos];
}
int find(int k, int pos)
{
    if (tree[pos] == k)
        return pos;
    if (k < tree[pos])
    {
        if (rela[pos][0] != -1)
            return find(k, rela[pos][0]);
        else
            return -1;
    }
    else
    {
        if (rela[pos][1] != -1)
            return find(k, rela[pos][1]);
        else
            return -1;
    }
}
int initialtree(int *tree, int s, int e, int father)
{
    if (e - s == 0)
    {
        return -1;
    }
    rela[s][2] = father;
    if (e - s == 1)
    {
        rela[s][0] = -1;
        rela[s][1] = -1;
        return s;
    }
    int kl = s + 1;
    while (kl < e && tree[kl] < tree[s])
        kl++;
    rela[s][0] = initialtree(tree, s + 1, kl, s);
    rela[s][1] = initialtree(tree, kl, e, s);
    return s;
}
int main(void)
{
    int test_num;
    scanf("%d %d", &test_num, &N_keys);
    for (int i = 0; i < N_keys; i++)
    {
        int k = 0;
        scanf("%d", &k);
        tree[i] = k;
    }
    initialtree(tree, 0, N_keys, -2);
    for (int i = 0; i < test_num; i++)
    {
        int a, b;
        int a_exit;
        scanf("%d %d", &a, &b);
        a_exit = read_key(a);
        int b_pos = find(b, 0);
        if (a_exit == -1 && b_pos == -1)
        {
            printf("ERROR: %d and %d are not found.\n", a, b);
        }
        else if (a_exit == -1 || b_pos == -1)
        {
            a_exit = a_exit == -1 ? a : b;
            printf("ERROR: %d is not found.\n", a_exit);
        }
        else
        {
            int lca = up_find(b_pos);
            if (lca == a)
            {
                printf("%d is an ancestor of %d.\n", a, b);
            }
            else if (lca == b)
            {
                printf("%d is an ancestor of %d.\n", b, a);
            }
            else
            {
                printf("LCA of %d and %d is %d.\n", a, b, lca);
            }
        }
    }
    return 0;
}