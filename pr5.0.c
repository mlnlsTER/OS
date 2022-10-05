#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>

struct Vector {
    double x;
    double y;
};

struct point {
    int mass;
    int pos;
    struct Vector coord;
};

struct point closerPointToAnotherPoint(struct point point1, struct point *points, int n) {
    struct point closerPoint;
    int i;
    double dist = 100000;
    for (i = 1; i < n; i++) {
        double curDist = sqrt(pow(point1.coord.x - points[i].coord.x, 2) + pow(point1.coord.y - points[i].coord.y, 2));
        if (curDist < dist) {
            dist = curDist;
            closerPoint = points[i];
        }
    }

    return closerPoint;
}

int main() {
	system("chcp 1251");
	system("cls");
    int i, n, j;
    printf("Кол-во точек: ");
    scanf("%d", &n);
    struct point points[100];
    for (i = 0; i < n; i++) {
        double x, y;
        int mass;
        printf("\nТочка №%d\nX: ", i + 1);
        scanf("%lf", &x);
        printf("Y: ");
        scanf("%lf", &y);
        printf("Масса: ");
        scanf("%d", &mass);

        points[i].coord.x = x;
        points[i].coord.y = y;
        points[i].mass = mass;
        points[i].pos = i;
    }

    int numb = n - 1;

    for (i = 0; i < numb; i++) {
        struct point pointToDelete = closerPointToAnotherPoint(points[0], points, n);
        printf("Удаление точки %d с координатами (%.1lf;%.1lf) и массой %d\n", pointToDelete.pos, pointToDelete.coord.x, pointToDelete.coord.y, pointToDelete.mass);
        points[0].mass += pointToDelete.mass;
        for (j = pointToDelete.pos; j < n - 1; j++) {
            points[j] = points[j + 1];
            points[j].pos = j;
        }
        n--;
    }
    printf("\nОставшаяся точка: %d", points[0].mass);
}
