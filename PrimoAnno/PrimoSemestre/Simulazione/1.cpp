#include <iostream>
#include <math.h>
using namespace std;
const int n = 10;
double rms(double x[n])
{
    double somma = 0, rms = 0, fract = 1 / n;
    for (int i = 0; i < n; i++)
    {
        if (x[i] > 1.0)
        {
            x[i] = 1.0;
        }
        if (x[i] < 1.0)
        {
            x[i] = -1.0;
        }
        somma += (x[i] * x[i]);
    }
    rms = sqrt(fract * somma);
    return rms;
}