// https://pintia.cn/problem-sets/994805342720868352/problems/994805351814119424
#include <stdio.h>
#include <iostream>

using namespace std;

const int max_v = 201;
bool graph[max_v][max_v];
int Nv;
int Ne;
bool vs[max_v];
bool check()
{
    fill(vs, vs + max_v, false);
    bool res = true;
    int n, v1;
    scanf("%d %d", &n, &v1);
    for (int i = 1; i < n; i++)
    {
        int v2;
        scanf("%d", &v2);
        if (graph[v1][v2] == false || vs[v2])
        {
            res = false;
        }
        vs[v2] = true;
        v1 = v2;
    }
    if (n - 1 != Nv)
        res = false;
    return res;
}

int main()
{
    fill(*graph, *graph + max_v * max_v, false);
    scanf("%d %d", &Nv, &Ne);
    for (int i = 0; i < Ne; i++)
    {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = true;
        graph[v2][v1] = true;
    }
    int count;
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        if (check())
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}