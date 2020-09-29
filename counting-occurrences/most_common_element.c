#include <stdio.h>
#include <stdlib.h>

int most_common_element(int nums[], size_t length)
{
    int counts[100] = {0};

    for (size_t i = 0; i < length; i++)
    {
        counts[nums[i]]++;
    }

    int highest_v = -1;
    int highest = -1;

    for (int i = 0; i < 100; i++)
    {
        if (counts[i] > highest_v)
        {
            highest_v = counts[i];
            highest = i;
        }
    }

    return highest;
}