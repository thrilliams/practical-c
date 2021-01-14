#include <math.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    double x;
    double y;
} point;

typedef struct
{
    point a;
    point b;
} line;

double dist(point a, point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double length(line l)
{
    return dist(l.a, l.b);
}

double slope(line l)
{
    return (l.b.y - l.a.y) / (l.b.x - l.a.x);
}

bool point_on_line(line l, point p)
{
    if (p.y == slope(l) * (p.x - l.a.x) + l.a.y)
    {
        return true;
    }
    return false;
}

int main(int argc, char *argv[])
{
    line l = {
        .a = {0, 0},
        .b = {3, 6}};

    printf("%i\n", point_on_line(l, (point){1, 3})); // 0

    printf("%i\n", point_on_line(l, (point){1, 2})); // 1

    printf("%i\n", point_on_line(l, (point){2, 4})); // 1
}
