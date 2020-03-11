// https://pintia.cn/problem-sets/994805342720868352/problems/994805374509498368
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define num_b 62
int sell[num_b];

int hash1(char c)
{
    int res = 0;
    if (c - '0' < 10 && c - '0' >= 0)
        res += c - '0';
    else if (c - 'a' < 26 && c - 'a' >= 0)
        res = 10 + c - 'a';
    else
        res = 36 + c - 'A';
    return res;
}
int main()
{
    fill(sell, sell + num_b, 0);
    char beads[10001];
    cin.getline(beads, 10001);
    int i = 0;
    while (beads[i] != '\0')
    {
        /* code */
        int k = hash1(beads[i]);
        sell[k]++;
        i++;
    }
    cin.getline(beads, 10001);
    i = 0;
    while (beads[i] != '\0')
    {
        /* code */
        int k = hash1(beads[i]);
        sell[k]--;
        i++;
    }
    int more = 0;
    int less = 0;
    for (i = 0; i < 62; i++)
    {
        if (sell[i] > 0)
            more += sell[i];
        else if (sell[i] < 0)
            less += sell[i];
    }
    if (less < 0)
    {
        printf("No %d", -less);
    }
    else
    {
        printf("Yes %d", more);
    }

    return 0;
}