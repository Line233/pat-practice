// https://pintia.cn/problem-sets/994805342720868352/problems/994805352925609984
#include <iostream>
#include <algorithm>
using namespace std;

#define hash_num 40
int *hash_table;
int n;
int id_num = 0;

int get_id(int k)
{
    int id = 0;
    while (k > 0)
    {
        id += k % 10;
        k /= 10;
    }
    return id;
}
void read()
{
    cin >> n;
    hash_table = (int *)malloc(sizeof(int) * hash_num);
    fill(hash_table, hash_table + hash_num, 0);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        int id = get_id(k);
        if (hash_table[id] == 0)
        {
            id_num++;
        }
        hash_table[id]++;
    }
}
void print()
{
    cout << id_num << endl;
    int in = 0;
    while (hash_table[in] == 0)
        in++;
    cout << in;
    in++;
    for (int i = in; i < hash_num; i++)
    {
        if (hash_table[i] != 0)
        {
            cout << " " << i;
        }
    }
}

int main(void)
{
    read();
    print();
}