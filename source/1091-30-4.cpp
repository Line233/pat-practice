//https://pintia.cn/problem-sets/994805342720868352/problems/994805375457411072
//SUMMARY 优先广度搜索
//TODO fixbug 内存超限
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>

using namespace std;
typedef struct node
{
    bool isstroke = false;
    bool read = false;
} node;
const int M = 1286;
const int N = 128;
const int L = 60;

node MAP[M][N][L];

int T, SM, SN, SL;
int Border[3];

bool inborder(int *in)
{
    for (int i = 0; i < 3; i++)
    {
        if (in[i] < 0 || in[i] >= Border[i])
            return false;
    }
    return true;
}
int *next(int *in, int i)
{
    static int pianyi[6][3] = {
        {-1, 0, 0},
        {1, 0, 0},
        {0, 1, 0},
        {0, -1, 0},
        {0, 0, 1},
        {0, 0, -1}};
    int *res = new int[3];
    for (int j = 0; j < 3; j++)
        res[j] = in[j] + pianyi[i][j];
    return res;
}

node *getnode(int *index)
{
    return &(MAP[index[0]][index[1]][index[2]]);
}
int bfs(int m, int n, int l)
{
    int count = 0;
    int *in = new int[3];
    in[0] = m;
    in[1] = n;
    in[2] = l;
    queue<int *> que;
    que.push(in);
    node *now = getnode(in);
    now->read = true;
    while (que.size() != 0)
    {
        in = que.front();
        now = getnode(in);
        count++;
        for (int i = 0; i < 6; i++)
        {
            int *in2 = next(in, i);
            now = getnode(in2);
            if (inborder(in2) && !now->read && now->isstroke)
            {
                now->read = true;
                que.push(in2);
            }
        }
        free(que.front());
        que.pop();
    }
    return count;
}

int main(void)
{
    cin >> SM >> SN >> SL >> T;
    Border[0] = SM;
    Border[1] = SN;
    Border[2] = SL;
    for (int i = 0; i < SL; i++)
        for (int j = 0; j < SM; j++)
            for (int k = 0; k < SN; k++)
            {
                int in;
                cin >> in;
                MAP[j][k][i].isstroke = (in == 1);
            }
    int count = 0;
    for (int i = 0; i < SL; i++)
        for (int j = 0; j < SM; j++)
            for (int k = 0; k < SN; k++)
            {
                int in[3] = {j, k, i};
                node *now = getnode(in);
                if (!now->read && now->isstroke)
                {
                    int size = bfs(j, k, i);
                    if (size >= T)
                        count += size;
                }
            }
    cout << count;
    return 0;
}