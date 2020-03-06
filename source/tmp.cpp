#include<stdio.h>
bool IsMeasurable(int target, int weights[], int nWeights)
{

    if (nWeights == 0)

    {

        if (target == 0)
            return true;

        else
            return false;
    }

    bool a = IsMeasurable(target - weights[nWeights - 1], weights, nWeights - 1);

    bool b = IsMeasurable(target, weights, nWeights - 1);

    bool c = IsMeasurable(target + weights[nWeights - 1], weights, nWeights - 1);

    return (a || b || c);
}
int main()
{

    int weights[] = {1, 3};

    int nWeights[]={2,3};
    nWeights=weights;

}
