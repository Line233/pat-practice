// https://pintia.cn/problem-sets/994805342720868352/problems/994805413520719872

#include <iostream>

using namespace std;

typedef struct num
{
    int *a;
    int n;
    int e;
    bool iszero;
} num;

num *read_num(int n)
{
    num *content = (num *)malloc(sizeof(num));
    content->n = n;
    content->a = (int *)malloc(sizeof(int) * n);
    content->e = 0;
    content->iszero = false;
    //
    char c;
    // bool beforedot = true;
    int firstnum = -1;
    int dot = -1;
    int index = 0;
    bool end = false;
    int count = 0;
    for (count = 0; !end; count++)
    {
        cin >> c;
        switch (c)
        {
        case '.':
            dot = count;
            break;
        case ' ':
            end = true;
            break;
        case '\n':
            end = true;
            break;
        case '0':
            if (index != n && index != 0)
            {
                content->a[index] = c - '0';
                index++;
            }
            break;
        default: //x
            if (index != n)
            {
                if (index == 0)
                    firstnum = count;
                content->a[index] = c - '0';
                index++;
            }
            break;
        }
    }
    if (index == 0)
        content->iszero = true;
    else
    {
        if (index != n)
        {
            for (int i = index; i < n; i++)
                content->a[i] = 0;
        }
        if (dot == -1)
            dot = count - 1;
        int e = dot - firstnum;
        e = e < 0 ? e + 1 : e;
        content->e = e;
    }
    return content;
}
bool compare_num(num n1, num n2)
{
    bool res = false;
    if (n1.e != n2.e)
        return false;
    for (int i = 0; i < n1.n; i++)
    {
        if (n1.a[i] != n2.a[i])
            return false;
    }
    return true;
}
void print_num(num n1)
{
    cout << "0.";
    for (int i = 0; i < n1.n; i++)
    {
        cout << n1.a[i];
    }
    cout << "*10^" << n1.e;
}

int main(void)
{
    int n;
    cin >> n;
    cin >> noskipws;
    char c;
    cin >> c;
    num *n1 = read_num(n);
    num *n2 = read_num(n);
    cin >> skipws;
    if (compare_num(*n1, *n2))
    {
        cout << "YES ";
        print_num(*n1);
    }
    else
    {
        cout << "NO ";
        print_num(*n1);
        cout << " ";
        print_num(*n2);
    }
    return 0;
}