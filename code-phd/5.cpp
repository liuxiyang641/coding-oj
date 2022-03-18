#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct fish {
    int w, a;
};

int cmp(const void * a, const void * b) {
    struct fish* x = (struct fish*) a;
    struct fish* y = (struct fish*) b;
    return x->w - y->w;
}

int main() {
    struct fish f[300000];
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &f[i].w, &f[i].a);
        }
        qsort(f, n, sizeof(struct fish), cmp);
        long long ans = f[0].w;
        long long accm = 0;
        for(int i = 1; i < n; ++i) {
            accm += f[i - 1].a;
            ans = ans > f[i].w - accm ? ans : f[i].w - accm;
        }
        printf("%lld\n", ans);
    }
    
}