//https://pintia.cn/problem-sets/994805342720868352/problems/994805449625288704
/*SUMMARY 
    数序列 
    输出值暂存处理 便于二次输出
    注意0值
*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

vector<string> nums;

bool cmp(string &str1, string &str2)
{
    string str1x = str1 + str2;
    string str2x = str2 + str1;
    return str1x.compare(str2x) < 0;
}
int main(void)
{
    int n;
    cin >> n;
    nums.resize(n);
    cin.get();
    char cx[10];
    for (int i = 0; i < n; i++)
    {
        cin >> cx;
        cin.get();
        nums[i] = cx;
    }
    sort(nums.begin(), nums.end(), cmp);
    string str;
    for (auto ite = nums.begin(); ite != nums.end(); ite++)
        str += *ite;
    int i = 0;
    while (str[i] == '0')
        i++;
    if (str.size() == i)
        cout << "0";
    else
        cout << str.substr(i);
    return 0;
}