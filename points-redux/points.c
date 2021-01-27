#include <stdlib.h>
#include <math.h>
#include <stdio.h>

typedef struct
{
    double x;
    double y;
} point;

typedef struct
{
    size_t point_count;
    point points[];
} polygon;

polygon *read_polygon(size_t point_count)
{
    polygon *p = malloc(sizeof(polygon) + point_count * sizeof(point));
    p->point_count = point_count;
    double x, y;

    printf("\nEnter your points, clockwise or counterclockwise,\none per line, with a space between the x and y coordinates.\n");

    for (size_t i = 0; i < point_count; i++)
    {
        scanf("%lf %lf", &x, &y);
        p->points[i] = (point){x, y};
    }

    return p;
}

double dist(point a, point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double perimeter(const polygon *p)
{
    double per = 0;

    for (size_t i = 0; i < p->point_count; i++)
    {
        per += dist(p->points[i], p->points[(i + 1) % p->point_count]);
    }

    return per;
}

double area(const polygon *p)
{
    double a = 0;

    for (size_t i = 0; i < p->point_count; i++)
    {
        a += (p->points[(i + 1) % p->point_count].x + p->points[i].x) * (p->points[(i + 1) % p->point_count].y - p->points[i].y);
    }

    return fabs(a / 2);
}

int main(int argc, char *argv[])
{
    size_t count;

    printf("How many points are on your polygon? ");
    scanf("%zu", &count);

    polygon *p = read_polygon(count);

    printf("\nPerimiter: %.3lf\n", perimeter(p));

    printf("Area: %.3lf\n", area(p));

    free(p);
}
