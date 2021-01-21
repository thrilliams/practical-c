#include <stdlib.h>
#include <math.h>
#include <stdio.h>

typedef struct
{
    double x;
    double y;
} point;

point *read_points(size_t count)
{
    point *points = calloc(count, sizeof(point));
    double x, y;

    printf("\nEnter your points, clockwise or counterclockwise,\none per line, with a space between the x and y coordinates.\n");

    for (size_t i = 0; i < count; i++)
    {
        scanf("%lf %lf", &x, &y);
        points[i] = (point){x, y};
    }

    return points;
}

double dist(point a, point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double perimeter(const point *points, size_t count)
{
    double p = 0;

    for (size_t i = 0; i < count; i++)
    {
        p += dist(points[i], points[(i + 1) % count]);
    }

    return p;
}

double area(const point *points, size_t count)
{
    double a = 0;

    for (size_t i = 0; i < count; i++)
    {
        a += (points[(i + 1) % count].x + points[i].x) * (points[(i + 1) % count].y - points[i].y);
    }

    return fabs(a / 2);
}

int main(int argc, char *argv[])
{
    size_t count;

    printf("How many points are on your polygon? ");
    scanf("%zu", &count);

    point *points = read_points(count);

    double p = perimeter(points, count);
    printf("\nPerimiter: %.3lf\n", p);

    double a = area(points, count);
    printf("Area: %.3lf\n", a);

    free(points);
}
