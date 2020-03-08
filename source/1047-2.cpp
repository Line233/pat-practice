// https://pintia.cn/problem-sets/994805342720868352/problems/994805433955368960
#include <iostream>
#include <algorithm>
#include <array>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
#define num_cou_max 2501
#define num_stu_max 40000
int table[num_cou_max][num_stu_max];
int sizes[num_cou_max];
int num_cou;
int gethash(char *c, int n)
{
    int res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        res += c[i];
        res *= 128;
    }
    res += c[n - 1];
    return res;
}
void dehash(int k, char *c, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        c[i] = k % 128;
        k /= 128;
    }
}
int main()
{
    int n_stu;
    scanf("%d %d", &n_stu, &num_cou);
    for (int i = 0; i < num_cou; i++)
        sizes[i] = 0;
    char str[5];
    int n_c;
    int hash;
    int k;
    for (int i = 0; i < n_stu; i++)
    {
        // cin >> str >> n_c;
        scanf("%s %d", str, &n_c);
        hash = gethash(str, 4);
        for (int j = 0; j < n_c; j++)
        {
            scanf("%d", &k);
            table[k][sizes[k]++] = hash;
        }
    }
    for (int i = 1; i <= num_cou; i++)
    {
        printf("%d %d\n", i, sizes[i]);
        sort(table[i], table[i] + sizes[i]);
        for (int j = 0; j < sizes[i]; j++)
        {
            dehash(table[i][j], str, 4);
            str[4] = '\0';
            printf("%s\n", str);
        }
    }
    return 0;
}