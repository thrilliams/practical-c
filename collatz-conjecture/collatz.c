#include <stdio.h>

int collatz_sequence(unsigned long n)
{
    int length = 0;
    while (n != 1)
    {
        n = (n % 2 == 0) ? n / 2 : (n * 3) + 1;
        length++;
    }

    return length;
}

int longest_sequence(int n)
{
    int longest = -1;
    int lvalue = -1;

    for (int i = 1; i < n; i++)
    {
        int length = collatz_sequence(i);
        if (length > lvalue)
        {
            lvalue = length;
            longest = i;
        }
    }

    return longest;
}

int highest_ratio(int n)
{
    int highest = -1;
    double hvalue = -1;

    for (double i = 1.0; i < n; i++)
    {
        double ratio = collatz_sequence(i) / i;
        if (ratio > hvalue)
        {
            hvalue = ratio;
            highest = i;
        }
    }

    return highest;
}

int main(int argc, char *argv[])
{
    int range = 100000;

    int longest = longest_sequence(range);
    printf("%i has a stopping time of %i\n", longest, collatz_sequence(longest));

    int highest = highest_ratio(range);
    int highest_length = collatz_sequence(highest);
    printf("%i has a stopping time of %i, which is about %.2f times larger than itself\n", highest, highest_length, highest_length / (double)highest);
}