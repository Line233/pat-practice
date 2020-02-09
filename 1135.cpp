// https://pintia.cn/problem-sets/994805342720868352/problems/994805346063728640
#define DEBUG
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;
int lengh = 0;
int *tree = NULL;

int *read(int n);
int bfs(int start, int num, int center);
bool isRedBlack();

int main()
{
#ifdef DEBUG
    ifstream ifile;
    ofstream ofile;
    ifile.open("data.txt");
    ofile.open("1135.txt");
    cout.rdbuf(ofile.rdbuf());
    cin.rdbuf(ifile.rdbuf());
#endif
    //
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> lengh;
        tree = read(lengh);
        if (isRedBlack())
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }
        cout << endl;
        free(tree);
    }
    //
#ifdef DEBUG
    ifile.close();
    ofile.close();
#endif
}
int *read(int n)
{
    int *res = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        cin >> res[i];
    return res;
}
int bfs(int start, int num, int center)
{
    if (center < 0 && tree[start] < 0)
        return -1;
    if (num == 1)
    {
        return tree[start] > 0 ? 1 : 0;
    }
    int c = abs(tree[start]);
    int l_n = start + 1;
    while (abs(tree[l_n]) < c && l_n < start + num)
        l_n++;
    l_n = l_n - start - 1;
    int bl = 0;
    if (l_n > 0)
        bl = bfs(start + 1, l_n, tree[start]);
    int r_n = num - 1 - l_n;
    int br = 0;
    if (r_n > 0)
        br = bfs(start + l_n + 1, r_n, tree[start]);
    if (bl == br && br != -1)
    {
        return bl + (tree[start] > 0 ? 1 : 0);
    }
    else
    {
        return -1;
    }
}
bool isRedBlack()
{
    if (tree[0] < 0)
        return false;
    int res = bfs(0, lengh, 0);
    return res != -1;
}