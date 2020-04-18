//https://pintia.cn/problem-sets/994805342720868352/problems/994805379664297984
//SUMMARY 多权重最短路径算法
//TODO fix bug

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <vector>
#include <climits>
using namespace std;

const int MaxCities = 200;
int MAP[MaxCities][MaxCities];
map<string, int> NameToInt;
map<int, string> IntToName;
typedef struct w
{
    int cost = INT_MAX;
    int lengh = INT_MAX;
    int h = 0;
} w;

struct wei
{
    w weight;
    int happiness = 0;
    bool read = false;
    int same = 0;
    int pre;
};
vector<wei> Weights;
int Ncity = 0;

int CityId(char *ch)
{
    static int index = 0;
    string name(ch);
    if (NameToInt.count(name) == 0)
    {
        NameToInt[name] = index;
        IntToName[index] = name;
        index++;
    }
    return NameToInt[name];
}
bool operator>(w w1, w w2)
{
    if (w1.cost != w2.cost)
        return w1.cost > w2.cost;
    else if (w1.h != w2.h)
        return w1.h < w2.h;
    else
        return w1.lengh > w2.lengh;
}
bool operator>=(w w1, w w2)
{
    if (w1.cost != w2.cost)
        return w1.cost > w2.cost;
    else if (w1.h != w2.h)
        return w1.h < w2.h;
    else
        return w1.lengh >= w2.lengh;
}
int findmin()
{
    int index = -1;
    w mincost;
    for (int i = 0; i < Weights.size(); i++)
    {
        if (!Weights[i].read && mincost > Weights[i].weight)
        {
            index = i;
            mincost = Weights[i].weight;
        }
    }
    return index;
}

w Add(int j, int i)
{
    //j to i
    w w1;
    w1.cost = Weights[j].weight.cost + MAP[i][j];
    w1.h = Weights[j].weight.h + Weights[i].happiness;
    w1.lengh = Weights[j].weight.lengh + 1;
    return w1;
}
void djk(int start)
{
    Weights[start].weight.cost = 0;
    Weights[start].weight.h = 0;
    Weights[start].weight.lengh = 0;
    Weights[start].read = false;
    int id = findmin();
    while (id != -1)
    {
        Weights[id].read = true;
        for (int i = 0; i < Ncity; i++)
        {
            if (!Weights[i].read && MAP[id][i] != INT_MAX)
            {
                w wnew = Add(id, i);
                if (Weights[i].weight.cost == wnew.cost)
                    Weights[i].same++;
                else if (Weights[i].weight.cost > wnew.cost)
                    Weights[i].same = 1;
                if (Weights[i].weight >= wnew)
                {
                    Weights[i].weight = wnew;
                    Weights[i].pre = id;
                }
            }
        }
        id = findmin();
    }
}

int main(void)
{
    int nroute;
    cin >> Ncity >> nroute;
    fill(*MAP, *MAP + MaxCities * MaxCities, INT_MAX);
    Weights.resize(Ncity);
    char name[4];
    cin >> name;
    int id = CityId(name);
    for (int i = 1; i < Ncity; i++)
    {
        int happiness;
        cin >> name >> happiness;
        int id = CityId(name);
        Weights[id].happiness = happiness;
    }
    for (int i = 0; i < nroute; i++)
    {
        char name1[4], name2[4];
        cin >> name1 >> name2;
        int a = CityId(name1), b = CityId(name2);
        cin >> MAP[a][b];
        MAP[b][a] = MAP[a][b];
    }
    djk(0);
    id = CityId("ROM");
    cout << Weights[id].same << " "
         << Weights[id].weight.cost << " "
         << Weights[id].weight.h << " "
         << (int)(Weights[id].weight.h / Weights[id].weight.lengh+0.5) << endl;
    vector<int> path;
    int pre = id;
    while (pre != 0)
    {
        path.push_back(pre);
        pre = Weights[pre].pre;
    }
    path.push_back(0);
    for (auto ite = path.rbegin(); ite != path.rend(); ite++)
    {
        cout << IntToName[*ite] << (ite == path.rend() - 1 ? "" : "->");
    }

    return 0;
}