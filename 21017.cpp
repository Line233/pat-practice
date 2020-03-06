#include <iostream>
#include <algorithm>
using namespace std;
#define N 10000
#define K 100

int windows[K];
int N_com;
int N_win;
typedef struct comsumor *node;
struct comsumor
{
    int arrive;
    int service;
    int wait;
    node next;
};
node com = NULL;

node insert(node com, int a, int s, int w)
{
    node p = (node)malloc(sizeof(struct comsumor));
    p->arrive = a;
    p->service = s;
    p->wait = w;
    if (com == NULL)
    {
        p->next = NULL;
        return p;
    }
    else if (com->arrive > p->arrive)
    {
        p->next = com;
        return p;
    }
    else
    {
        node pre = com;
        node com2 = com->next;
        while (com2 && com2->arrive < p->arrive)
        {
            pre = com2;
            com2 = com2->next;
        }
        pre->next = p;
        p->next = com2;
        return com;
    }
}
int min_win()
{
    int min_w = windows[0];
    int min_in = 0;
    for (int i = 0; i < N_win; i++)
    {
        if (windows[i] < min_w)
        {
            min_w = windows[i];
            min_in = i;
        }
    }
    return min_in;
}
int main()
{
    cin >> N_com >> N_win;
    int n_acl=N_com;
    for (int i = 0; i < N_com; i++)
    {
        int h, m, s;
        cin >> h;
        cin.get();
        cin >> m;
        cin.get();
        cin >> s;
        int m2;
        cin >> m2;
        if (((h * 60) + m) * 60 + s > 17 * 60 * 60)
        {
            n_acl--;
            continue;
        }
        com = insert(com, ((h * 60) + m) * 60 + s, m2 * 60, 0);
    }
    N_com=n_acl;
    for (int i = 0; i < N_win; i++)
        windows[i] = 8 * 60 * 60;
    node current = com;
    while (current)
    {

        int min_w = min_win();

        windows[min_w] = max(current->arrive, windows[min_w]);
        current->wait = windows[min_w] - current->arrive;
        windows[min_w] += current->service;

        current = current->next;
    }
    int wait = 0;
    while (com)
    {
        wait += com->wait;
        com = com->next;
    }
    printf("%.1f", (float)wait / 60 / N_com);
    return 0;
}