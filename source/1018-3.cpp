//https://pintia.cn/problem-sets/994805342720868352/problems/994805489282433024
//SUMMARY 图，最短路径算法，深度优先搜索
//TODO fix bug
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <vector>
#include <limits.h>

using namespace std;

int Capicity;
int Nstations;
int Error;
int Nedges;

int Bikes[510];

int Edges[510][510];

vector<int> Pre[510];
int Lengh[510];
bool Reached[510];

int dijstic();
int findmin();

vector<int> minpath;
int minweight[2] = {INT_MAX, INT_MAX};
vector<int> path;
int weight[2] = {INT_MAX, INT_MAX};

int dfs(int v);
void compute(int &takemax, int &over);

int main(void)
{
    fill(*Edges, *Edges + 510 * 510, -1);
    scanf("%d%d%d%d", &Capicity, &Nstations, &Error, &Nedges);
    for (int i = 1; i <= Nstations; i++)
        scanf("%d", &Bikes[i]);
    for (int i = 0; i < Nedges; i++)
    {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        Edges[a][b] = w;
        Edges[b][a] = w;
    }
    dijstic();
    dfs(Error);
    printf("%d 0", minweight[0]);
    for (int i = minpath.size() - 2; i >= 0; i--)
    {
        printf("->%d", minpath[i]);
    }
    printf(" %d", weight[1]);

    return 0;
}

int findmin()
{
    int mina = INT_MAX;
    int minindex = 0;
    for (int i = 0; i <= Nstations; i++)
    {
        if (Reached[i])
            continue;
        else if (mina > Lengh[i])
        {
            minindex = i;
            mina = Lengh[i];
        }
    }
    return minindex;
}
void compute()
{
    int over = 0, maxtake = 0;
    int pre = 0;
    for (int i = path.size() - 2; i >= 0; i--)
    {
        over += (Bikes[path[i]] - Capicity / 2);
        if (over < 0)
        {
            maxtake += -over;
            over = 0;
        }
    }
    weight[0] = maxtake;
    weight[1] = over;
}
int dfs(int v)
{
    path.push_back(v);
    if (v == 0)
    {
        compute();
        if (minweight[0] > weight[0] || (minweight[0] == weight[0] && minweight[1] > weight[1]))
        {
            minweight[0] = weight[0];
            minweight[1] = weight[1];
            minpath = path;
        }
    }
    else
    {
        for (int i = Pre[v].size() - 1; i >= 0; i--)
        {
            dfs(Pre[v][i]);
        }
    }
    path.pop_back();
    return 0;
}
int dijstic()
{
    fill(Lengh, Lengh + 510, INT_MAX);
    fill(Reached, Reached + 510, false);
    int now = 0;
    Lengh[now] = 0;
    Reached[now] = true;
    int count=0;
    while (count<Nstations)
    {
        for (int i = 1; i <= Nstations; i++)
        {
            if (Edges[now][i] == -1 || Reached[i])
                continue;
            if (Lengh[now] + Edges[now][i] < Lengh[i])
            {
                Lengh[i] = Lengh[now] + Edges[now][i];
                Pre[i].clear();
                Pre[i].push_back(now);
            }
            else if (Lengh[now] + Edges[now][i] == Lengh[i])
            {
                Pre[i].push_back(now);
            }
        }
        now = findmin();
        Reached[now] = true;
        count++;
    }
    return 0;
}
