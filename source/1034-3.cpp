//https://pintia.cn/problem-sets/994805342720868352/problems/994805456881434624
//SUMMARY 哈希表，交并集
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

map<string, int> NameId;
map<int, string> IdName;

int TotalWeights[3000];
int Gangs[3000];
int GangWeights[3000];

int id_Max = 0;

int findgang(int id)
{
    while (Gangs[id] >= 0 && id < id_Max)
    {
        id = Gangs[id];
    }
    return id;
}
int UnionGang(int a, int b)
{
    int ag = findgang(a);
    int bg = findgang(b);
    if (ag != bg)
    {
        int size = Gangs[ag] + Gangs[bg];
        int weight = GangWeights[ag] + GangWeights[bg];
        if (TotalWeights[ag] > TotalWeights[bg])
        {
            Gangs[bg] = ag;
            Gangs[ag] = size;
            GangWeights[ag] = weight;
            return ag;
        }
        else
        {
            Gangs[ag] = bg;
            Gangs[bg] = size;
            GangWeights[bg] = weight;
            return bg;
        }
    }
    return ag;
}

int GetId(string name)
{
    if (NameId.count(name) <= 0)
    {
        NameId[name] = id_Max;
        IdName[id_Max] = name;
        id_Max++;
    }
    return NameId[name];
}
int main(void)
{
    fill(TotalWeights, TotalWeights + 3000, 0);
    fill(GangWeights, GangWeights + 3000, 0);
    fill(Gangs, Gangs + 3000, -1);
    int nphones, threhold;
    cin >> nphones >> threhold;
    int id = 0;
    vector<int> pairs;
    for (int i = 0; i < nphones; i++)
    {
        char name[4], name2[4];
        int time;
        cin >> name >> name2 >> time;
        int id1 = GetId(name);
        int id2 = GetId(name2);
        TotalWeights[id1] += time;
        TotalWeights[id2] += time;
        GangWeights[id1] += time;
        GangWeights[id2] += time;
        pairs.push_back(id1);
        pairs.push_back(id2);
    }

    //union bang
    for (int i = 0; i < pairs.size(); i += 2)
    {
        UnionGang(pairs[i], pairs[i + 1]);
    }

    vector<string> bangs;
    for (int i = 0; i < id_Max; i++)
    {
        if (Gangs[i] < -2 && GangWeights[i] > threhold * 2)
        {
            string name = IdName[i];
            bangs.push_back(name);
        }
    }
    cout << bangs.size() << endl;
    sort(bangs.begin(), bangs.end());
    for (auto itor = bangs.begin(); itor != bangs.end(); itor++)
    {
        int id = GetId(*itor);
        cout << *itor << " " << (-Gangs[id]) << endl;
    }

    return 0;
}