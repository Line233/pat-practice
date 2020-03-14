// https://pintia.cn/problem-sets/994805342720868352/problems/994805344776077312
//SUMMARY 图，图的边的数量会超过图的点的数量！！图小心回路
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
typedef struct nodex
{
    int a1;
    int a2;
} node;
#define max_peo 400
int people[max_peo][max_peo + 1];
int read;
int num_friends[max_peo];
int N_peo;
node path[max_peo * max_peo]; //重要！！

int getpath(int a1x, int a2x)
{
    int count = 0;
    int f1, f2;
    for (int i = 1; i < num_friends[a1x]; i++)
    {
        f1 = people[a1x][i];
        if (people[f1][0] * people[a1x][0] < 0 || f1 == a2x)
            continue;
        for (int j = 1; j < num_friends[a2x]; j++)
        {
            f2 = people[a2x][j];
            if (people[f2][0] * people[a2x][0] < 0 || f2 == a1x)
                continue;
            for (int k = 1; k < num_friends[f2]; k++)
            {
                if (people[f2][k] == f1)
                {
                    path[count].a1 = abs(people[f1][0]);
                    path[count].a2 = abs(people[f2][0]);
                    count++;
                    break;
                }
            }
        }
    }
    return count;
}
bool cmp(node a1, node a2)
{
    if (a1.a1 != a2.a1)
    {
        return a1.a1 < a2.a1;
    }
    else
        return a1.a2 < a2.a2;
}
void add_rela(int a1x, int a2x)
{
    people[a1x][num_friends[a1x]++] = a2x;
}
void print(int k)
{
    char num[5];
    for (int i = 3; i >= 0; i--)
    {
        num[i] = k % 10 + '0';
        k /= 10;
    }
    num[4] = '\0';
    printf("%s", num);
}
int findx(int k)
{
    for (int i = 0; i < read; i++)
    {
        if (people[i][0] == k)
            return i;
    }
    people[read++][0] = k;
    return read - 1;
}
int main()
{
    fill(*people, *people + max_peo * (max_peo + 1), 0);
    fill(num_friends, num_friends + max_peo, 1);
    int n_rela;
    scanf("%d %d", &N_peo, &n_rela);
    for (int i = 0; i < n_rela; i++)
    {
        int a1, a2;
        scanf("%d %d", &a1, &a2);
        int x = findx(a1);
        int x2 = findx(a2);
        add_rela(x, x2);
        add_rela(x2, x);
    }
    int n_love;
    scanf("%d", &n_love);
    for (int i = 0; i < n_love; i++)
    {
        int a1, a2;
        scanf("%d %d", &a1, &a2);
        int countPath = getpath(findx(a1), findx(a2));
        printf("%d\n", countPath);
        sort(path, path + countPath, cmp);
        for (int j = 0; j < countPath; j++)
        {
            print(path[j].a1);
            printf(" ");
            print(path[j].a2);
            printf("\n");
        }
    }
    return 0;
}
