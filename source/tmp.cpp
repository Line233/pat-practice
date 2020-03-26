// website
//SUMMARY template
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;

int main(void)
{
    char p[] = "abcdefgh";
    char *p2 = p + 3;
    p2 = strcpy(p2, "ABCD");
    cout << strlen(p2);
    return 0;
}