// https://pintia.cn/problem-sets/994805342720868352/problems/994805361586847744
//SUMMARY 交并集
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define max_hobbies 1001
int hobbies[max_hobbies];
int clusters[max_hobbies];
int root(int a)
{
    while (hobbies[a] != -1)
        a = hobbies[a];
    return a;
}
void merge(int a, int b)
{
    int ra = root(a);
    int rb = root(b);
    if (ra != rb)
    {
        hobbies[rb] = ra;
        clusters[ra] += clusters[rb];
        clusters[rb] = 0;
    }
}
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    fill(hobbies, hobbies + max_hobbies, -1);
    fill(clusters, clusters + max_hobbies, 0);
    int n;
    int max_hobby = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int k = 0, fisrt;
        scanf("%d", &k);
        getchar();
        scanf("%d", &fisrt);
        if (fisrt > max_hobby)
            max_hobby = fisrt;
        int r = root(fisrt);
        if (k != 1)
        {
            for (int j = 1; j < k; j++)
            {
                int c;
                scanf("%d", &c);
                merge(r, c);
                if (c > max_hobby)
                    max_hobby = c;
            }
        }
        clusters[root(fisrt)]++;
    }
    sort(clusters, clusters + max_hobby + 1, cmp);
    int i = 0;
    while (i < max_hobbies && clusters[i] > 0)
        i++;
    printf("%d\n", i);
    for (int k = 0; k < i - 1; k++)
    {
        printf("%d ", clusters[k]);
    }
    printf("%d", clusters[i - 1]);
    return 0;
}