// https://pintia.cn/problem-sets/994805342720868352/problems/994805390896644096
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

#define max_sents 100
#define max_lengh 257

int num_sents;
char sents[max_sents][max_lengh];
int lenghs[max_sents];

int find_min()
{
    int mini = 0;
    int mink = lenghs[mini];
    for (int i = 1; i < num_sents; i++)
    {
        if (lenghs[i] < mink)
        {
            mini = i;
            mink = lenghs[i];
        }
    }
    return mini;
}
bool cmp()
{
    for (int i = 0; i < num_sents - 1; i++)
    {
        if (sents[i][lenghs[i]] != sents[i + 1][lenghs[i + 1]])
            return false;
    }
    return true;
}
void sub()
{
    for (int i = 0; i < num_sents; i++)
    {
        lenghs[i]--;
    }
}
int main()
{
    fill(lenghs, lenghs + max_sents, 0);
    scanf("%d", &num_sents);
    cin.get();
    for (int i = 0; i < num_sents; i++)
    {
        cin.getline(sents[i], max_lengh);
        lenghs[i] = strlen(sents[i]);
    }
    int k = lenghs[find_min()];
    sub();
    for (int i = 0; i < k && cmp(); i++)
    {
        sub();
    }
    if (sents[0][lenghs[0] + 1] == '\0')
        printf("nai");
    else
        printf("%s", sents[0] + lenghs[0] + 1);
    return 0;
}