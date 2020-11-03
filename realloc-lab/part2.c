#include <stdio.h>
#include <stdlib.h>

int *insert(int *original_array, size_t original_length, int new_element, size_t new_index)
{
    int *new_array = realloc(original_array, (original_length + 1) * sizeof(int));
    for (size_t i = 0; i <= original_length; i++)
    {
        if (i < new_index)
        {
            new_array[i] = original_array[i];
        }
        else if (i == new_index)
        {
            new_array[i] = new_element;
        }
        else if (i > new_index)
        {
            new_array[i] = original_array[i - 1];
        }
    }
    if (new_array != original_array)
    {
        free(original_array);
    }
    return new_array;
}

int main()
{
    int *nums = malloc(2 * sizeof(int));

    nums[0] = 100;
    nums[1] = 22;
    printf("%i\n", nums[0]);
    printf("%i\n", nums[1]);

    nums = insert(nums, 2, 420, 1);

    printf("%i\n", nums[0]);
    printf("%i\n", nums[1]);
    printf("%i\n", nums[2]);
}