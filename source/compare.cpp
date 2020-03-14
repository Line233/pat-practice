#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
bool compare(string name1, string name2);
vector<int> errors;
int main(int argc, char **argv)
{
    bool issame = true;
    for (int i = 2; i < argc; i++)
    {
        string str1(argv[i - 1]);
        string str2(argv[i]);
        if (!compare(str1, str2))
        {
            issame = false;
        }
    }
    if (issame)
        cout << "pass";
    else
    {
        cout << "errors:"
             << "\t";
        for (int i = 0; i < errors.size(); i++)
        {
            cout << "\t" << errors[i] << endl;
        }
    }
    return 0;
}
bool compare(string name1, string name2)
{
    bool isSame = true;
    ifstream data1, data2;
    data1.open(name1);
    data2.open(name2);
    string str1, str2;
    int line = 1;
    bool over1 = false, over2 = false;
    while (!(over1 && over2))
    {
        if (!getline(data1, str1))
            over1 = true;
        if (!getline(data2, str2))
            over2 = true;
        if (over1 != over2)
        {
            errors.push_back(line);
            isSame = false;
            break;
        }
        else if (over1 == true)
            break;
        else
        {
            if (str1!= str2)
            {
                isSame = false;
                errors.push_back(line);
            }
        }
        line++;
    }
    return isSame;
}