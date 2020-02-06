// https://pintia.cn/problem-sets/994805342720868352/problems/994805376476626944
#include <iostream>
using namespace std;

int *menbers;
int men_num;
double price;
float interest;

int level;
int highlevel_num;

void read()
{
    cin >> men_num >> price >> interest;
    menbers = (int *)malloc(sizeof(int) * men_num);
    for (int i = 0; i < men_num; i++)
        cin >> menbers[i];
}
int get_level(int* tree,int* level,int i)
{
    if(level[i]==-1)
        return get_level(tree,level,tree[i])+1;
}
void get_highest_level()
{
    int *done = (int *)malloc(sizeof(int) * men_num);
    for (int i = 0; i < men_num; i++)
        done[i] = -1;
    for (int i = 0; i < men_num; i++)
    {
        if (done[i] == -1)
        {
            int lev = 0;
            int k = i;
            while (k != -1)
            {
                if (done[k] != -1)
                {
                    lev += done[k];
                    break;
                }
                k = menbers[k];
                lev++;
            }
            if (lev > level)
            {
                level = lev;
                highlevel_num = 1;
            }
            else if (lev == level)
            {
                highlevel_num++;
            }
            k = i;
            while (done[k] == -1 && lev > 0)
            {
                done[k] = lev;
                k = menbers[k];
                lev--;
            }
        }
    }
    if (level != 0)
        level--;
}
void print()
{
    float r = 1 + interest / 100;
    double p = price;
    for (int i = 0; i < level; i++)
    {
        p *= r;
    }
    printf("%.2lf %d", p, highlevel_num);
}
int main(void)
{
    read();
    get_highest_level();
    print();
    return 0;
}