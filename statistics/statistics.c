#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sum(const double *nums, size_t count)
{
    double s = 0;
    for (size_t i = 0; i < count; i++)
    {
        s += nums[i];
    }

    return s;
}

double mean(const double *nums, size_t count)
{
    return sum(nums, count) / count;
}

double std_dev(const double *nums, size_t count)
{
    double s = 0;
    for (size_t i = 0; i < count; i++)
    {
        s += pow(nums[i] - mean(nums, count), 2);
    }
    return sqrt(s / count);
}

double *read_array(size_t count)
{
    double *nums = calloc(count, sizeof(double));
    printf("Enter %zu numbers, one per line:\n", count);
    for (size_t i = 0; i < count; i++)
    {
        scanf("%lf", &(nums[i])); // this makes me feel unclean
    }
    return nums;
}

int main(int argc, char *argv[])
{
    size_t length;
    printf("How many numbers will you enter? ");
    scanf("%zu", &length);

    double *nums = read_array(length);

    printf("\n");
    printf("Sum: %f\n", sum(nums, length));
    printf("Mean: %f\n", mean(nums, length));
    printf("Standard deviation: %f\n", std_dev(nums, length));

    return 0;
}