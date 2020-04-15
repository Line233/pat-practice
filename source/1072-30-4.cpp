//https://pintia.cn/problem-sets/994805342720868352/problems/994805396953219072
/*SUMMARY 
    有限点的最短路径算法
    多次dijstic算法
*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <climits>

using namespace std;

const int MaxDot = 1011;
int CityMap[MaxDot][MaxDot];

int Nhouse;
int Ncsta;
int Ndots;
int Nrange;

typedef struct node
{
    int id = 0;
    float average = INT_MAX;
    int min = INT_MAX;
} node;
vector<node> res;
typedef struct node2
{
    int weight = INT_MAX;
    bool read = false;
} node2;
int HouseId(int k)
{
    return 10 + k;
}
int getint(string str)
{
    int sum = 0;
    for (auto ite = str.begin(); ite != str.end(); ite++)
    {
        sum = sum * 10 + *ite - '0';
    }
    return sum;
}
int DotId(char *c)
{
    if (c[0] == 'G')
    {
        string str(c + 1);
        return getint(str);
    }
    else
    {
        string str(c);
        return HouseId(getint(str));
    }
}
int findmin(vector<node2> weights)
{
    int minx = INT_MAX, index = -1;
    for (int i = 1; i < weights.size(); i++)
    {
        if (weights[i].read == false && minx >= weights[i].weight)
        {
            minx = weights[i].weight;
            index = i;
        }
    }
    return index;
}
bool cmp(node &a, node &b)
{
    if (a.min != b.min)
        return a.min >= b.min;
    else if (a.average != b.average)
        return a.average < b.average;
    else
        return a.id < b.id;
}
void djk(int start)
{
    int sum = 0;
    int mindist = INT_MAX;
    vector<node2> weights(Ndots + 1);
    weights[start].weight = 0;
    int in = findmin(weights);
    while (in != -1)
    {
        if (in > 10)
        {
            if (weights[in].weight > Nrange)
                return;
            sum += weights[in].weight;
            if (weights[in].weight < mindist)
                mindist = weights[in].weight;
        }
        weights[in].read = true;
        for (int i = 1; i <= Ndots; i++)
        {
            if (weights[i].read)
                continue;
            if (CityMap[in][i] != INT_MAX &&
                weights[i].weight > CityMap[in][i] + weights[in].weight)
                weights[i].weight = CityMap[in][i] + weights[in].weight;
        }
        in = findmin(weights);
    }
    node r;
    r.average = (float)sum / (float)Nhouse;
    r.id = start;
    r.min = mindist;
    res.push_back(r);
    return;
}

int main(void)
{
    fill(*CityMap, *CityMap + MaxDot * MaxDot, INT_MAX);
    int nroad;
    cin >> Nhouse >> Ncsta >> nroad >> Nrange;
    Ndots = 10 + Nhouse;
    for (int i = 0; i < nroad; i++)
    {
        char dot[10];
        cin >> dot;
        int a = DotId(dot);
        cin >> dot;
        int b = DotId(dot);
        int wei;
        cin >> wei;
        CityMap[a][b] = wei;
        CityMap[b][a] = wei;
    }
    for (int i = 1; i <= Ncsta; i++)
        djk(i);

    if (res.size() == 0)
        cout << "No Solution";
    else
    {
        sort(res.begin(), res.end(), cmp);
        cout << 'G' << res[0].id << endl;
        printf("%0.1f %0.1f", (float)res[0].min, res[0].average);
    }
    return 0;
}