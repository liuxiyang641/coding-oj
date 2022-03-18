
#include<stdio.h>
#include<math.h>

double PI = 3.14159265;

double cal(double x) {
    return (sin(sqrt(x)) + exp(-pow(x, 1.0 / 3))) / log(PI * x);
}

double searchRoot(double left, double right, double y) {
    double mid = left + (right - left) / 2;
    double ymid = cal(mid);
    if(fabs(ymid - y) <= 1e-7) {
        return mid;
    }
    else {
        if(ymid > y + 1e-7) {
            return searchRoot(mid, right, y);
        }
        else {
            return searchRoot(left, mid, y);
        }
    }
}

int main() {
    double y;
    while(~scanf("%lf", &y)) {
        printf("%.5lf\n", searchRoot(0.33, 10, y));
    }
}