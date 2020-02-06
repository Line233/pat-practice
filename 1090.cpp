// https://pintia.cn/problem-sets/994805342720868352/problems/994805376476626944
#include <iostream>
using namespace std;

int *menbers;
int men_num;
float price;
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
void get_highest_level()
{
    bool *done = (bool *)malloc(sizeof(bool) * men_num);
    for (int i = 0; i < men_num; i++)
        done[i] = false;
    for (int i = 0; i < men_num; i++)
    {
        if (done[i] == false)
        {
            int lev = 0;
            int k = i;
            while (k != -1)
            {
                done[k] = true;
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
        }
    }
    if (level != 0)
        level--;
}
void print()
{
    float r = 1 + interest/100;
    float p = price;
    for (int i = 0; i < level; i++)
    {
        p *= r;
    }
    // for (int i = 0; i < level; i++)
    // {
    //     p /= 100;
    // }
    printf("%.2f %d",p,highlevel_num);
}
int main(void)
{
    read();
    get_highest_level();
    print();
    return 0;
}