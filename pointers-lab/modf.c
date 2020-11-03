#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    double x, f, i;

    x = 3.141592;
    f = modf(x, &i);

    printf("%.0f point %f\n", i, f);
}