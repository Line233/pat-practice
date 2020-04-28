// website
//https://pintia.cn/problem-sets/994805342720868352/problems/994805392092020736 
//SUMMARY 优先广度搜索
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
typedef struct node
{
    vector<int> to;
    bool read = false;
} node;
vector<node> Graph;
int Level;

int bfs(int s)
{
    queue<int> stack;
    int count = 0;
    int lev = 0;
    stack.push(s);
    stack.push(-1);
    while (stack.size() != 0 && lev <= Level)
    {
        int k = stack.front();
        if (k == -1)
        {
            lev++;
            stack.push(-1);
        }
        else if (!Graph[k].read)
        {
            count++;
            Graph[k].read = true;
            for (int i = 0; i < Graph[k].to.size(); i++)
            {
                if (!Graph[Graph[k].to[i]].read)
                {
                    stack.push(Graph[k].to[i]);
                }
            }
        }
        stack.pop();
    }
    return count - 1;
}

int main(void)
{
    int nuser;
    cin >> nuser >> Level;
    Graph.resize(nuser);
    for (int i = 0; i < nuser; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int user;
            cin >> user;
            Graph[user - 1].to.push_back(i);
        }
    }
    vector<int> RES;
    int nq;
    cin >> nq;
    for (int i = 0; i < nq; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < Graph.size(); j++)
            Graph[j].read = false;
        RES.push_back(bfs(k - 1));
    }
    for (int i = 0; i < RES.size(); i++)
    {
        cout << RES[i] << endl;
    }

    return 0;
}