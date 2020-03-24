#include "generator.h"
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int RandBetween(int low, int high) //not include high
{
    if (low == high)
        return low;
    return rand() % (high - low) + low;
}

void PrintGraph(int **graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (graph[i][j] > 0)
                cout << i << " " << j << " " << graph[i][j] << endl;
        }
    }
}
void PrintArray(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i];
        if (i != n - 1)
            cout << " ";
    }
}
int *GenerateArray(int n, int low, int high)
{
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = RandBetween(low, high);
    }
    return arr;
}
bool BigFirst(int &a, int &b)
{
    if (a < b)
    {
        int tmp = a;
        a = b;
        b = tmp;
        return true;
    }
    else
        return false;
}
int **GenerateGraph(int n, int m, int low_w, int high_w)
{
    if (m < n - 1)
        exit(-1);
    int **gra = new int *[n];
    for (int i = 0; i < n; i++)
    {
        gra[i] = new int[n];
        fill(gra[i], gra[i] + n, -1);
    }
    for (int i = 1; i < n; i++)
    {
        int k = RandBetween(0, i);
        gra[i][k] = RandBetween(low_w, high_w);
        gra[k][i] = gra[i][k];
    }
    int count = n - 1;
    while (count < m)
    {
        int a = RandBetween(0, n);
        int b = RandBetween(0, n);
        if (gra[a][b] == -1)
        {
            gra[a][b] = RandBetween(low_w, high_w);
            gra[b][a] = gra[a][b];
            count++;
        }
    }
    return gra;
}
