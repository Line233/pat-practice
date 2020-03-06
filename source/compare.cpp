#include <iostream>
#include <fstream>
using namespace std;
bool compare(string name1, string name2);
int main(int argc, char **argv)
{
    bool issame = true;
    for (int i = 2; i < argc; i++)
    {
        string str1(argv[i - 1]);
        string str2(argv[i]);
        if (!compare(str1, str2))
        {
            return 0;
        }
    }
    cout << "same";
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
    while (getline(data1, str1) && getline(data2, str2))
    {
        int i = str1.compare(str2);
        if (i != 0)
        {
            isSame = false;
            cout << "different line: " << line << endl;
        }
        line++;
    }
    if (str1.size() != str2.size())
    {
        isSame = false;
        cout << "different line: " << line << endl;
    }
    return isSame;
}