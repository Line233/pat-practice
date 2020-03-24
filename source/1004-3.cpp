// website
//SUMMARY 倒置树
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

const int MaxNodes = 100;
int NNodes;

int Parents[MaxNodes];
int Level[MaxNodes];
bool Isparents[MaxNodes];
int RES[MaxNodes];

int _level_parent(int k)
{
    int p = Parents[k];
    if (Level[p] != -1)
    {
        return Level[p];
    }
    else
    {
        int level = _level_parent(p);
        Level[p] = level + 1;
        return Level[p];
    }
}
int GetLevel()
{
    Level[1] = 1;
    int Max_level = 0;
    for (int i = 1; i < NNodes + 1; i++)
    {
        if (Level[i] == -1)
        {
            Level[i] = _level_parent(i) + 1;
        }
        if (Level[i] > Max_level)
            Max_level = Level[i];
        if (!Isparents[i])
            RES[Level[i]]++;
    }
    return Max_level;
}
int main(void)
{
    fill(RES, RES + MaxNodes, 0);
    fill(Isparents, Isparents + MaxNodes, false);
    fill(Level, Level + MaxNodes, -1);
    int m;
    scanf("%d %d", &NNodes, &m);
    for (int i = 0; i < m; i++)
    {
        int id, k;
        scanf("%d %d", &id, &k);
        if (k != 0)
            Isparents[id] = true;
        for (int j = 0; j < k; j++)
        {
            int sub;
            scanf("%d", &sub);
            Parents[sub] = id;
        }
    }

    int max_level = GetLevel();
    for (int i = 1; i < max_level + 1; i++)
    {
        printf("%d%s", RES[i], i == max_level ? "" : " ");
    }
    return 0;
}