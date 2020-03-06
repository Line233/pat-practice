// https://pintia.cn/problem-sets/994805342720868352/problems/994805437411475456

#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int find_max_index(int *lis, int end)
{
    int max = 0;
    for (int i = 0; i < end; i++)
    {
        if (lis[i] > lis[max])
        {
            max = i;
        }
    }
    return max;
}
int *read_n(int n)
{
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    return arr;
}
int *get_hash(int *lst_like, int color_num, int lst_num)
{
    //lst_like   1-N
    color_num++;
    int *hash = (int *)malloc(sizeof(int) * color_num);
    fill(hash, hash + color_num, -1);
    for (int i = 0; i < lst_num; i++)
    {
        hash[lst_like[i]] = i;
    }
    return hash;
}
int convert_hash(int *lst, int *hash, int n)
{
    int lst_num = 0;
    for (int i = 0; i < n; i++)
    {
        if (hash[lst[i]] != -1)
        {
            lst[lst_num] = hash[lst[i]];
            lst_num++;
        }
    }
    return lst_num;
}

int max_len(int *lst, int lst_num, int like_num)
{
    int *score = (int *)malloc(sizeof(int) * like_num);
    fill(score, score + like_num, 0);
    int num, max;
    for (int i = 0; i < lst_num; i++)
    {
        num = lst[i];
        max = find_max_index(score, num + 1);
        score[num] = score[max] + 1;
    }
    int res = score[find_max_index(score, like_num)];
    free(score);
    return res;
}

int main(void)
{
    int color_num, like_num, lst_num;
    cin >> color_num;
    cin >> like_num;
    int *like = read_n(like_num);
    cin >> lst_num;
    int *lst = read_n(lst_num);

    int *hash = get_hash(like, color_num, like_num);
    int lis_num_new = convert_hash(lst, hash, lst_num);
    cout << max_len(lst, lis_num_new, like_num);
    return 0;
}