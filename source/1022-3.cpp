//https://pintia.cn/problem-sets/994805342720868352/problems/994805480801550336
//SUMMARY map,整行输入，字符串分割
//TODO fix bug
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <set>

using namespace std;

map<string, set<string, less<string>>> Infos[5];
int main(void)
{
    int nbooks;
    cin >> nbooks;
    for (int i = 0; i < nbooks; i++)
    {
        char id[10];
        char info[80];
        cin >> id;
        cin.get();
        string idstr(id);
        for (int j = 0; j < 5; j++)
        {
            cin.getline(info, 80);
            string str(info);
            if (j != 2)
                Infos[j][str].insert(idstr);
            else
            {
                char keyword[6];
                int m = 0;
                int k = 0;
                while (info[k] != '\0')
                {
                    keyword[m] = info[k];
                    m++;
                    k++;
                    if (info[k] == ' ' || info[k] == '\0')
                    {
                        keyword[m] = '\0';
                        str = string(keyword);
                        Infos[j][str].insert(idstr);
                        m = 0;
                        if (info[k] == ' ')
                            k++;
                    }
                }
            }
        }
    }
    int nquries;
    cin >> nquries;
    cin.get();
    for (int i = 0; i < nquries; i++)
    {
        char info[85];
        cin.getline(info, 85);
        string str(info);
        str = str.substr(3);
        cout << info << endl;
        int key = info[0] - '0';
        key--;
        // sort(Infos[key][str].begin(), Infos[key][str].end());
        if (Infos[key][str].size() == 0)
            cout << "Not Found" << endl;
        else
            for (auto j = Infos[key][str].begin(); j != Infos[key][str].end(); j++)
            {
                cout << *j << endl;
            }
    }
    return 0;
}