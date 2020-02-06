// https://pintia.cn/problem-sets/994805342720868352/problems/994805376476626944
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int *menbers;
int men_num;
double price = 0;
double interest = 0;
int root = 0;

int level = 0;
int highlevel_num = 0;

void read()
{
    cin >> men_num >> price >> interest;
    menbers = (int *)malloc(sizeof(int) * men_num);
    for (int i = 0; i < men_num; i++)
    {
        cin >> menbers[i];
        if (menbers[i] == -1)
            root = i;
    }
}
int get_level(int *tree, int *level, int i)
{
    if (level[i] == -1)
    {
        int le = get_level(tree, level, tree[i]) + 1;
        level[i] = le;
        return le;
    }
    else
    {
        return level[i];
    }
}
void get_highest_level()
{
    int *done = (int *)malloc(sizeof(int) * men_num);
    for (int i = 0; i < men_num; i++)
        done[i] = -1;
    done[root] = 0;
    for (int i = 0; i < men_num; i++)
    {
        int l = get_level(menbers, done, i);
        if (l > level)
        {
            level = l;
            highlevel_num = 1;
        }
        else if (l == level)
        {
            highlevel_num++;
        }
    }
}
void print()
{
    double p = price * pow(1 + interest / 100, level);
    char c[50];
    sprintf(c, "%.2lf %d", p, highlevel_num);
    cout << c;
}
int main(void)
{
    // ifstream ifile;
    // ofstream ofile;
    // ifile.open("data.txt");
    // ofile.open("1090.txt");
    // cout.rdbuf(ofile.rdbuf());
    // cin.rdbuf(ifile.rdbuf());
    //
    try
    {
        read();
        get_highest_level();
        print();
    }
    catch (int e)
    {
        cout << "error";
    }

    //
    // ifile.close();
    // ofile.close();
    //
    return 0;
}