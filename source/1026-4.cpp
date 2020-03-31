//https://pintia.cn/problem-sets/994805342720868352/problems/994805472333250560
//SUMMARY模拟
//TODO fix bugs
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

enum optype
{
    in = 0,
    out = 1
};
typedef struct player
{
    bool isvip = false;
    int arrive = 0;
    int play = 0;
    int leave = 0;
} player;
typedef struct table
{
    bool isvip = false;
    int served = 0;
    bool ing = 0;
} table;
typedef struct myop
{
    int time = 0;
    int play = 0;
    int tal = 0;
    optype type = in;
} myop;
int CLOCK = 0;
int Atalbe = 0;
int Avip = 0;
vector<player> Players;
vector<table> Tables;
deque<myop> OPs;

int HtoInt(int h, int m, int s)
{
    return ((h - 8) * 60 + m) * 60 + s;
}
void InttoH(int k, int &h, int &m, int &s)
{
    s = k % 60;
    k /= 60;
    m = k % 60;
    k /= 60;
    h = (k + 8);
}
void printtime(int t)
{
    int h, m, s;
    InttoH(t, h, m, s);
    printf("%02d:%02d:%02d ", h, m, s);
}
int waittime(int arri, int ser)
{
    int d = ser - arri;
    return d / 60 + (d % 60 != 0 ? 1 : 0);
}
void InOps(myop op1)
{
    auto ite = OPs.begin();
    while (ite != OPs.end() && op1.time > ite->time)
        ite++;
    OPs.insert(ite, op1);
}
int FindTable(bool isVip)
{
    int i = 0;
    for (; i < Tables.size(); i++)
    {
        if (!Tables[i].ing && ((isVip && Avip != 0) ? Tables[i].isvip : true))
            return i;
    }
}
deque<myop>::iterator findinvip()
{
    auto ite = OPs.begin();
    while (ite != OPs.end() && ite->time < CLOCK)
    {
        if (Players[ite->play].isvip)
            break;
        ite++;
    }
    return ite;
}
void Exin(myop op1)
{
    int t = FindTable(Players[op1.play].isvip);
    Players[op1.play].leave = CLOCK + Players[op1.play].play;
    op1.tal = t;

    Tables[op1.tal].served++;
    Tables[op1.tal].ing = true;
    Atalbe--;
    if (Tables[op1.tal].isvip)
        Avip--;

    myop opout = op1;
    opout.type = out;
    opout.time = Players[op1.play].leave;
    InOps(opout);
    if (CLOCK < (21 - 8) * 60 * 60)
    {
        printtime(Players[op1.play].arrive);
        printtime(CLOCK);
        cout << waittime(Players[op1.play].arrive, CLOCK) << endl;
    }
}
void Exout(myop op1)
{
    Tables[op1.tal].ing = false;
    Atalbe++;
    if (Tables[op1.tal].isvip)
        Avip++;
}
void Exe(deque<myop>::iterator ite)
{
    myop op1 = *ite;
    OPs.erase(ite);
    if (CLOCK < op1.time)
        CLOCK = op1.time;
    switch (op1.type)
    {
    case in:
        Exin(op1);
        break;
    case out:
        Exout(op1);
        break;
    }
}

int main(void)
{
    int nplayers;
    cin >> nplayers;
    for (int i = 0; i < nplayers; i++)
    {
        int h, m, s, pt, isvip;
        cin >> h;
        cin.get();
        cin >> m;
        cin.get();
        cin >> s;
        cin >> pt >> isvip;
        player p;
        p.arrive = HtoInt(h, m, s);
        p.play = pt * 60;
        p.isvip = (isvip == 1);
        Players.push_back(p);
        myop op1;
        op1.time = p.arrive;
        op1.play = Players.size() - 1;
        InOps(op1);
    }

    cin >> Atalbe >> Avip;
    Tables.resize(Atalbe);
    for (int i = 0; i < Avip; i++)
    {
        int vip;
        cin >> vip;
        Tables[vip - 1].isvip = true;
    }

    while (OPs.size() != 0 && OPs.front().time < (21 - 8) * 60 * 60 && CLOCK < (21 - 8) * 60 * 60)
    {
        auto ite = OPs.begin();
        if (Atalbe == 0) //
        {
            while (ite != OPs.end() && ite->type == in)
                ite++;
        }
        else
        {
            if (Avip != 0)
                ite = findinvip();
            if (!Players[ite->play].isvip)
                ite = OPs.begin();
        }
        Exe(ite);
    }
    for (int i = 0; i < Tables.size(); i++)
    {
        cout << Tables[i].served;
        if (i != Tables.size() - 1)
            cout << " ";
    }
    return 0;
}