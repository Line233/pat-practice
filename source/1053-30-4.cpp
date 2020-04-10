// website
/*SUMMARY 
    树
    深度优先搜索
*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

typedef struct node
{
    int id = 0;
    int weight = 0;
    vector<int> children;
} node;

vector<node> Tree;
vector<vector<int>> Res;
int Nnode = 0;
int Wei;
bool cmp(int a, int b)
{
    return Tree[a].weight > Tree[b].weight;
}
void dfs(int t, int sum, vector<int> &path)
{
    sum += Tree[t].weight;
    path.push_back(Tree[t].weight);
    if (Tree[t].children.size() == 0)
    {
        if (sum == Wei)
            Res.push_back(path);
    }
    else
    {
        if (sum < Wei)
            for (auto ite = Tree[t].children.begin(); ite != Tree[t].children.end(); ite++)
            {
                dfs(*ite, sum, path);
            }
    }
    sum-=Tree[t].weight;
    path.pop_back();
    return;
}

int main(void)
{
    int m;
    cin >> Nnode >> m >> Wei;
    Tree.resize(Nnode);
    for (int i = 0; i < Nnode; i++)
    {
        Tree[i].id = i;
        cin >> Tree[i].weight;
    }
    for (int i = 0; i < m; i++)
    {
        int id, n;
        cin >> id >> n;
        for (int j = 0; j < n; j++)
        {
            int c;
            cin >> c;
            Tree[id].children.push_back(c);
        }
        sort(Tree[id].children.begin(), Tree[id].children.end(),cmp);
    }
    vector<int> p;
    dfs(0,0,p);
    for(auto ite=Res.begin();ite!=Res.end();ite++)
    {
        for(auto ite2=ite->begin();ite2!=ite->end();ite2++)
        {
            cout<<*ite2<<((ite2+1==ite->end())?"":" ");
        }
        cout<<endl;
    }
    return 0;
}