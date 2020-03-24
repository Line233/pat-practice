//https://pintia.cn/problem-sets/994805342720868352/problems/994805498207911936
//SUMMARY template
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <deque>

using namespace std;

typedef struct people
{
    int index = 0;
    int time = 0;
    int end;
} people;

const int MaxWins = 20;
const int MaxCap = 10;
const int MaxPeo = 1000;

int NWins;
int Ncap;
int Npeo;

deque<int> Bank[MaxWins];
deque<int> Queue;
people Customers[MaxPeo];

int myclock = 0;
int Capacity = 0;
int MaxCapacity;

int SumTime(deque<int> &a)
{
    int suma = 0;
    deque<int>::iterator ita = a.begin();
    while (ita != a.end())
    {
        suma += Customers[*ita].time;
        ita++;
        /* code */
    }
    return suma;
}
int MinTran()
{
    int min = 100000;
    int index = 0;
    for (int i = 0; i < NWins; i++)
    {
        if (Bank[i].size() != 0)
        {
            int b = Customers[Bank[i][0]].time;
            if (b < min)
            {
                min = b;
                index = i;
            }
        }
    }
    return index;
}
int MinQueue()
{
    if (Capacity == MaxCapacity)
        return -1;
    int min = 1000000;
    int index = 0;
    for (int i = 0; i < NWins; i++)
    {
        if (Bank[i].size() < Ncap)
        {
            int b = SumTime(Bank[i]);
            if (b < min)
            {
                min = b;
                index = i;
            }
        }
    }
    return index;
}
void outBack()
{
    if (Capacity != 0)
    {
        int a = MinTran();
        int t = Customers[Bank[a][0]].time;
        myclock += t;
        for (int i = 0; i < NWins; i++)
        {
            if (Bank[i].size() != 0)
            {
                Customers[Bank[i][0]].time -= t;
                if (Customers[Bank[i][0]].time == 0)
                {
                    Customers[Bank[i].front()].end = myclock;
                    Bank[i].pop_front();
                    Capacity--;
                }
            }
        }
    }
}
void InBack()
{
    while (Capacity < MaxCapacity && Queue.size() != 0)
    {
        int a = MinQueue();
        Bank[a].push_back(Queue.front());
        Queue.pop_front();
        Capacity++;
    }
}
int main(void)
{
    int quries;
    scanf("%d %d %d %d", &NWins, &Ncap, &Npeo, &quries);
    MaxCapacity = NWins * Ncap;
    for (int i = 1; i <= Npeo; i++)
    {
        Customers[i].index = i;
        scanf("%d", &(Customers[i].time));
        Customers[i].end = 0;
        Queue.push_back(i);
    }
    while (Queue.size() != 0 || Capacity != 0)
    {
        InBack();
        outBack();
    }
    for (int i = 0; i < quries; i++)
    {
        int k;
        cin >> k;
        int end = Customers[k].end;
        int h = end / 60 + 8;
        int m = end % 60;
        if (h < 17 || (h == 17 && m == 0))
        {
            if (h < 10)
                printf("0");
            printf("%d:", h);
            if (m < 10)
                printf("0");
            printf("%d\n", m);
        }
        else
        {
            printf("Sorry\n");
        }
    }
    return 0;
}