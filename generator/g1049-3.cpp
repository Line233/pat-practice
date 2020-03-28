#include "generator.h"
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int main()
{
    srand(time(NULL));
    cout << rand() % 1000000000;
    return 0;
}
