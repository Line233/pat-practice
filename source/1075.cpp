//https://pintia.cn/problem-sets/994805342720868352/problems/994805393241260032
#include <iostream>
#include <algorithm>
using namespace std;

int user_num, pro_num, sub_num;
int *scores;
int *prob_grade;
int *total;
int *perfect;
int *submit;

int *initial(int n, int defaultnum = 0)
{
    int *res = (int *)malloc(sizeof(int) * n);
    fill(res, res + n, defaultnum);
    return res;
}
int score_index(int user, int prob)
{
    int res = (user - 1) * pro_num + prob - 1;
    return res;
}
void read()
{
    prob_grade = initial(pro_num);
    for (int i = 0; i < pro_num; i++)
        cin >> prob_grade[i];
    //
    scores = initial(user_num * pro_num, -1);
    total = initial(user_num, -1);
    perfect = initial(user_num);

    for (int i = 0; i < sub_num; i++)
    {
        int user, prob, grade;
        cin >> user >> prob >> grade;
        int ind = score_index(user, prob);
        if (total[user - 1] == -1 && grade != -1)
            total[user - 1] = 0;
        if (scores[ind] == -1)
        {
            scores[ind] = 0;
        }
        if (grade > scores[ind])
        {
            total[user - 1] = total[user - 1] - scores[ind] + grade;
            scores[ind] = grade;
            if (grade == prob_grade[prob - 1])
                perfect[user - 1]++;
        }
    }
}
int compare(int i, int j)
{
    if (total[i] != total[j])
        return total[i] - total[j];
    else
    {
        return perfect[i] - perfect[j];
    }
}
void print_num(int i)
{
    int e = 0;
    int a = i;
    while (a > 0)
    {
        a /= 10;
        e++;
    }
    for (int count = 0; count < 5 - e; count++)
    {
        cout << '0';
    }
    cout << i;
}
void print(int *sort)
{
    int i = 0;
    int last_total = 1;
    int last_rank = 0;
    int user = sort[i];
    while (i < user_num && total[user] != -1)
    {
        if (total[user] == last_total)
            cout << last_rank << " ";
        else
        {
            cout << i + 1 << " ";
            last_rank = i + 1;
        }
        print_num(user + 1);
        cout << " " << total[user];
        for (int j = 0; j < pro_num; j++)
        {
            cout << " ";
            int in = score_index(user + 1, j + 1);
            if (scores[in] == -1)
                cout << "-";
            else
                cout << scores[score_index(user + 1, j + 1)];
        }
        cout << endl;
        i++;

        last_total = total[user];
        user = sort[i];
    }
}
void merge(int *sort, int *tmp, int n1, int n2)
{
    int i = 0, j = n1, k = 0;
    while (i < n1 && j < n1 + n2)
    {
        if (compare(sort[i], sort[j]) >= 0)
        {
            tmp[k] = sort[i];
            i++;
        }
        else
        {
            tmp[k] = sort[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        tmp[k] = sort[i];
        k++;
        i++;
    }
    while (j < n1 + n2)
    {
        tmp[k] = sort[j];
        k++;
        j++;
    }
}
int *mergesort(int *sort, int n)
{
    int *tmp = initial(n);
    for (int i = 2; i / 2 < n; i *= 2)
    {
        for (int j = 0; j < n; j += i)
        {
            if (n - j < i / 2)
            {
            }
            else if (n - j < i)
            {
                merge(sort + j, tmp + j, i / 2, n - j - i / 2);
            }
            else
                merge(sort + j, tmp + j, i / 2, i - i / 2);
        }
        int *p = tmp;
        tmp = sort;
        sort = p;
    }
    free(tmp);
    return sort;
}

int *sort_my()
{
    int *res = initial(user_num);
    for (int i = 0; i < user_num; i++)
    {
        res[i] = i;
    }

    return mergesort(res, user_num);
}

int main(void)
{
    cin >> user_num >> pro_num >> sub_num;
    read();
    int *sorted = sort_my();
    print(sorted);
    return 0;
}