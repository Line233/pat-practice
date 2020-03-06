// https://pintia.cn/problem-sets/994805342720868352/problems/1038430013544464384
#define DEBUG
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;

int city_num = 0;
int edge_num = 0;
int graph[201][201];
int path[200];
int path_lengh;

void read();
void read2();
int compute(bool *ists);
void print(int i, int dict, bool ists);
int main()
{
#ifdef DEBUG
    ifstream ifile;
    ofstream ofile;
    ifile.open("data.txt");
    ofile.open("1150.txt");
    cout.rdbuf(ofile.rdbuf());
    cin.rdbuf(ifile.rdbuf());
#endif
    read();
    int path_min = 0;
    int dict_min = 10000000;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        read2();
        bool isTS = false;
        int dict = compute(&isTS);
        if (isTS && abs(dict) < dict_min)
        {
            path_min = i + 1;
            dict_min = abs(dict);
        }
        print(i + 1, dict, isTS);
    }
    cout << "Shortest Dist(" << path_min << ") = " << dict_min;
#ifdef DEBUG
    ifile.close();
    ofile.close();
#endif
    return 0;
}
void print(int i, int dict, bool ists)
{
    cout << "Path " << i << ": ";

    if (dict == 0)
        cout << "NA ";
    else
        cout << abs(dict) << " ";
    if (ists && dict > 0)
        cout << "(TS simple cycle)";
    else if (ists && dict < 0)
        cout << "(TS cycle)";
    else
        cout << "(Not a TS cycle)";

    cout << endl;
}
int compute(bool *ists)
{
    int cities[201];
    fill(cities, cities + 201, 0);
    int cs = city_num;
    int dict = 0;
    for (int i = 1; i < path_lengh; i++)
    {
        int k = graph[path[i - 1]][path[i]];
        if (k >= 0)
        {
            dict += k;
            if (cities[path[i - 1]] == 0)
            {
                cities[path[i - 1]] = 1;
                cs--;
            }
        }
        else
        {
            *ists = false;
            return 0;
        }
    }
    *ists = false;
    if (cs == 0 && path[0] == path[path_lengh - 1])
    {
        *ists = true;
        if (path_lengh - 1 > city_num)
            dict *= -1;
    }
    return dict;
}
void read2()
{
    cin >> path_lengh;
    for (int i = 0; i < path_lengh; i++)
    {
        cin >> path[i];
    }
}
void read()
{
    fill((int *)graph, (int *)graph + sizeof(graph) / sizeof(int), -1);
    cin >> city_num >> edge_num;
    for (int i = 0; i < edge_num; i++)
    {
        int city1, city2, dict;
        cin >> city1 >> city2 >> dict;
        graph[city1][city2] = dict;
        graph[city2][city1] = dict;
    }
}