// https://pintia.cn/problem-sets/994805342720868352/problems/994805363117768704
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

int n = 0;
int row = 0;
int column = 0;
int *numbers = NULL;

void read();
void get_row_colume();
bool cmp(int a, int b);
void print(int *matrix);
int print_circle(int *matrix, int *nums, int irow, int icolume, int row_ex, int colume_ex, int num_ex);
int index(int i, int j, int _row);
int *getmatrix();

int main(void)
{
    ifstream ifile;
    ofstream ofile;
    ifile.open("data.txt");
    ofile.open("1105.txt");
    cout.rdbuf(ofile.rdbuf());
    cin.rdbuf(ifile.rdbuf());
    //
    read();
    get_row_colume();
    stable_sort(numbers, numbers + n, cmp);
    int *m = getmatrix();
    print(m);
    free(m);
    //
    ifile.close();
    ofile.close();
}
int *getmatrix()
{
    int *matrix = (int *)malloc(sizeof(int) * n);
    int print_row = row, print_column = column, row_ex = 0, colume_ex = 0, num_ex = 0;
    while (num_ex != n)
    {
        num_ex = print_circle(matrix, numbers, print_row, print_column, row_ex, colume_ex, num_ex);
        print_row -= 2;
        print_column -= 2;
        row_ex++;
        colume_ex++;
    }
    return matrix;
}
void print(int *matrix)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column - 1; j++)
        {
            cout << matrix[index(i, j, column)] << " ";
        }
        cout << matrix[index(i, column - 1, column)] << endl;
    }
}
int print_circle(int *matrix, int *nums, int irow, int icolume, int row_ex, int colume_ex, int num_ex)
{
    if (icolume == 1)
    {
        for (int i = 0; i < irow; i++, num_ex++)
        {
            int in = index(i + row_ex, colume_ex, column);
            matrix[in] = nums[num_ex];
        }
        return num_ex;
    }
    int i = 0, j = 0, k = num_ex;
    for (; j < icolume - 1; j++, k++)
    {
        int in = index(i + row_ex, j + colume_ex, column);
        matrix[in] = nums[k];
    }
    for (; i < irow - 1; i++, k++)
    {
        int in = index(i + row_ex, j + colume_ex, column);
        matrix[in] = nums[k];
    }
    for (; j > 0; j--, k++)
    {
        int in = index(i + row_ex, j + colume_ex, column);
        matrix[in] = nums[k];
    }
    for (; i > 0; i--, k++)
    {
        int in = index(i + row_ex, j + colume_ex, column);
        matrix[in] = nums[k];
    }
    return k;
}
void read()
{
    cin >> n;
    numbers = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
}
int index(int i, int j, int colume)
{
    return i * colume + j;
}

void get_row_colume()
{
    int k = sqrt(n);
    int i = 0;
    for (i = k; k > 0; i--)
    {
        if (n % i == 0)
            break;
    }
    column = i;
    row = n / i;
}
bool cmp(int a, int b)
{
    return a >= b;
}