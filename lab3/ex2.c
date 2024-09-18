#include<stdio.h>
#include<math.h>

typedef struct {
    float x;
    float y;
} Point;

float distance(Point a, Point b){
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

float area(Point a, Point b, Point c){
    return 0.5 * fabs(a.x * b.y - b.x * a.y + b.x * c.y - c.x * b.y + c.x * a.y - a.x * c.y);
}

int main(){
    Point A = {2.5, 6};
    Point B = {1, 2.2};
    Point C = {10, 6};

    float dist = distance(A, B);
    float triangleArea = area (A, B, C);

    printf("Distance: %.2f\nArea: %.2f\n", dist, triangleArea);
    return 0;
}