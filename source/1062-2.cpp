// https://pintia.cn/problem-sets/994805342720868352/problems/994805413520719872
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <array>

using namespace std;
typedef struct Peo
{
    int id;
    int v;
    int t;
    int total;
    int rank;
} peo;

#define peo_max 100001
array<peo, peo_max> people;
int num_p;
int num_act = 0;
bool cmp(peo p1, peo p2)
{
    bool res;
    if (p1.rank != p2.rank)
        res = p1.rank > p2.rank;
    else if (p1.total != p2.total)
        res = p1.total > p2.total;
    else if (p1.v != p2.v)
        res = p1.v > p2.v;
    else
    {
        res = p1.id < p2.id;
    }
    return res;
}
int main()
{
    int L, H;
    scanf("%d %d %d", &num_p, &L, &H);
    for (int i = 0; i < num_p; i++)
    {
        int v, t, id;
        scanf("%d %d %d", &id, &v, &t);
        if (v >= L && t >= L)
        {
            people[num_act].id = id;
            people[num_act].v = v;
            people[num_act].t = t;
            people[num_act].total = v + t;
            if (v >= H && t >= H)
                people[num_act].rank = 4;
            else if (v >= H && t < H)
                people[num_act].rank = 3;
            else if (v < H && t < H && t <= v)
                people[num_act].rank = 2;
            else
                people[num_act].rank = 1;
            num_act++;
        }
    }
    sort(people.begin(), people.begin() + num_act, cmp);
    char name[9];
    printf("%d\n", num_act);
    for (int i = 0; i < num_act; i++)
    {
        int id = people[i].id;
        for (int j = 7; j >= 0; j--)
        {
            name[j] = id % 10 + '0';
            id /= 10;
        }
        name[8] = '\0';
        printf("%s %d %d\n", name, people[i].v, people[i].t);
    }
    return 0;
}