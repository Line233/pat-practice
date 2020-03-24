// website
//SUMMARY template
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include "generator.h"

using namespace std;

int main(void)
{
    srand(time(NULL));

    int n, c, error, m;

    n = RandBetween(5, 500);
    c = RandBetween(1, 50);
    error = RandBetween(1, n + 1);
    m = RandBetween(n + 1, 2 * (n + 1));
    // m=1;

    int **gra = GenerateGraph(n + 1, m, 1, 2);
    int *caps = GenerateArray(n, 1, c);

    cout << c << " " << n << " " << error << " " << m << endl;
    PrintArray(caps, n);
    cout << endl;
    PrintGraph(gra, n + 1);

    return 0;
}