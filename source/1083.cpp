#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

typedef struct people
{
    char name[11];
    char id[11];
    int grade;
} people;


void print_people(people p)
{
    cout << p.name << " " << p.id<<endl;
    return;
}
int main(void)
{
    array<int, 101> grades;
    grades.fill(-1);
    int n, grade1, grade2;
    people *p = new people[101];

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin>>p[i].name;
        cin>>p[i].id;
        cin >> p[i].grade;
        cin.ignore();
        grades[p[i].grade] = i;
    }
    cin >> grade1;
    cin >> grade2;

    int k = 0;
    for (int i = grade2; i >= grade1; i--)
    {
        if (grades[i] != -1)
        {
            print_people(p[grades[i]]);
            k++;
        }
    }
    if (k == 0)
        cout << "NONE";
}
