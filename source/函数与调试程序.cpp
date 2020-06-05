// website
/*SUMMARY 
    template
*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;
void traverse(vector<vector<int>> vec, int s, int e, vector<vector<double>> &groups)
{
    if (vec[s][e] == -1)
    {
        vector<double> g;
        g.push_back(s);
        g.push_back(e);
        groups.push_back(g);
    }
    else
    {
        traverse(vec, s, vec[s][e], groups);
        traverse(vec, vec[s][e] + 1, e, groups);
    }
}

double findmax(vector<double> vec, int i, int j)
{
    double max = 0.0;
    for (int k = i; k < j; k++)
    {
        if (max < vec[k])
            max = vec[k];
    }
    return max;
}
vector<vector<double>> get_groups(int num_people, vector<vector<double>> &P)
{
    vector<vector<double>> K(num_people);
    vector<double> Ptmp(num_people);
    for (int i = 0; i < num_people; i++)
    {
        K[i].resize(num_people);
        Ptmp.clear();
        Ptmp.resize(num_people);
        for (int j = i; j < num_people; j++)
        {
            if (i == j)
            {
                K[i][j] = P[i][j];
                Ptmp[j] = P[i][j];
            }
            else
            {
                Ptmp[j] = 0;
                for (int k = i; k < j; k++)
                    Ptmp[k] += P[j][k];
                for (int k = i; k <= j; k++)
                    Ptmp[j] += P[k][j];
                K[i][j] = findmax(Ptmp, i, j + 1);
            }
        }
    }

    vector<vector<int>> path;
    path.resize(num_people);
    for (int i = 0; i < num_people; i++)
    {
        path[i].resize(num_people);
        fill(path[i].begin(), path[i].end(), -1);
    }

    for (int s = 1; s < num_people; s++)
    {
        for (int i = 0; i + s < num_people; i++)
        {
            for (int j = i; j + 1 <= i + s; j++)
            {
                if (K[i][i + s] < K[i][j] + K[j + 1][i + s])
                {
                    K[i][i + s] = K[i][j] + K[j + 1][i + s];
                    path[i][i + s] = j;
                }
            }
        }
    }
    vector<vector<double>> result;
    vector<double> sum = {K[0][num_people - 1]};
    result.push_back(sum);
    traverse(path, 0, num_people - 1, result);
    return result;
}

int main(void)
{
    int num_people;
    cin >> num_people;
    vector<vector<double>> P;
    P.resize(num_people);
    for (int i = 0; i < num_people; i++)
    {
        P[i].resize(num_people);
        for (int j = 0; j < num_people; j++)
            cin >> P[i][j];
    }
    vector<vector<double>> result = get_groups(num_people, P);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            cout<<result[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}