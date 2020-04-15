// website
/*SUMMARY 
    template
*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <climits>

using namespace std;

const int MaxDot = 1011;
int CityMap[MaxDot][MaxDot];
typedef struct node
{
    int id = 0;
    float average = INT_MAX;
    int min = INT_MAX;
} node;

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
bool cmp(node &a, node &b)
{
    if (a.min != b.min)
        return a.min >= b.min;
    else if (a.average != b.average)
        return a.average < b.average;
    else
        return a.id < b.id;
}

int Nhouse;
int Ncsta;
int Ndots;
int Nrange;

int main(void)
{
    fill(*CityMap, *CityMap + MaxDot * MaxDot, INT_MAX);
    int nroad;
    cin >> Nhouse >> Ncsta >> nroad >> Nrange;
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
    Ndots = 10 + Nhouse;
    for (int i = 1; i <= Ndots; i++)
        for (int j = 1; j <= Ndots; j++)
            for (int k = 1; k <= Ndots; k++)
            {
                if (CityMap[j][i] != INT_MAX && CityMap[i][k] != INT_MAX)
                {
                    CityMap[j][k] = min(CityMap[j][k], CityMap[j][i] + CityMap[i][k]);
                    CityMap[k][j] = CityMap[j][k];
                }
            }
    vector<node> res;

    for (int i = 1; i <= Ncsta; i++)
    {
        int sum = 0;
        int count = 0;
        int minx = INT_MAX;
        bool right = true;
        for (int j = 11; j <= Ndots; j++)
        {
            if (CityMap[j][i] != INT_MAX)
            {
                if (CityMap[j][i] > Nrange)
                {
                    right = false;
                    break;
                }
                sum += CityMap[j][i];
                count++;
                minx = min(minx, CityMap[j][i]);
            }
        }
        if (right)
            res.push_back({i, (float)sum / (float)count, minx});
    }
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