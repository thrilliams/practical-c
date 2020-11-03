#include <stdio.h>
#include <stdlib.h>

int *resize(int *original_array, size_t original_length, size_t new_length)
{
    int *new_array = malloc(new_length * sizeof(int));
    for (size_t i = 0; i < new_length; i++)
    {
        if (i < original_length)
        {
            new_array[i] = original_array[i];
        }
        else
        {
            new_array[i] = 0;
        }
    }
    free(original_array);
    return new_array;
}

int main()
{
    int *nums = malloc(2 * sizeof(int));

    nums[0] = 100;
    nums[1] = 22;
    printf("%i\n", nums[0]);

    nums = resize(nums, 2, 10);

    nums[2] = 33;
    nums[3] = 555;
    nums[9] = 1;
    printf("%i\n", nums[3]);
    printf("%i\n", nums[4]);

    return 0;
}