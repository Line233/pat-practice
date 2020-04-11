//https://pintia.cn/problem-sets/994805342720868352/problems/994805417945710592
/*SUMMARY 
    栈
*/
//TODO fix bug
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

vector<int> stack;
vector<int> cmp;
const string pop = "Pop";
const string push = "Push";
const string pm = "PeekMedian";

int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string op;
        cin >> op;
        if (op == pop)
        {
            if (stack.size() != 0)
            {
                int k = stack.back();
                cout << k << endl;
                stack.pop_back();
                for (auto ite = cmp.begin(); ite != cmp.end(); ite++)
                {
                    if (*ite == k)
                    {
                        cmp.erase(ite);
                        break;
                    }
                }
            }
            else
                cout << "Invalid" << endl;
        }
        else if (op == push)
        {
            int k;
            cin >> k;
            stack.push_back(k);
            auto ite = cmp.begin();
            while ((ite != cmp.end()) && *ite < k)
                ite++;
            cmp.insert(ite, k); //在ite之前插入
        }
        else
        {
            if (stack.size() != 0)
            {
                int index = (stack.size() + 1) / 2 - 1;
                cout << cmp[index] << endl;
            }
            else
                cout << "Invalid" << endl;
        }
    }
    return 0;
}