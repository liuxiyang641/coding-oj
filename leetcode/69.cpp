#include <stdio.h>
using namespace std;

int mySqrt(int x)
{
    if (x==0) return 0;
    int sqrt, mid;
    int l = 1, r = x;
    while(l<=r)
    {   
        // 注意这里的写法，防止超出界限!!!
        mid = l + (r-l)/2;
        sqrt = x/mid;
        if (mid == sqrt) return mid;
        else if (mid < sqrt)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return r;
}

int main(int argc, char** argv)
{
    int x;
    while(scanf("%d", &x)!=EOF)
    {
        printf("%d\n", mySqrt(x));
    }
    return 0;
}