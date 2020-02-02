#include <iostream>
#include<array>
using namespace std;

typedef struct people{
    int height;
    int age;
}people;

int main()
{
    cout << "hello world" << endl;
    char str[10];
    cin >> str;
    cout<<str<<endl;

    array<people,10> p;
    for(int i=0;i<10;i++)
    {
        p[i].age=i;
        p[i].height=i*10;
    }
    for(int i=0;i<10;i++)
    {
        cout<<p[i].age<<"  "<<p[i].height<<endl;
    }


    cin.get();
    return 0;
}