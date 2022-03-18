// https://leetcode.com/problems/random-pick-with-weight/
// 加权随机采样，这里需要学会c语言中产生随机数的方法，srand(time(NULL)); (double)(rand() / RAND_MAX)就可以获得0-1范围的随机数

#include<algorithm>
#include<math.h>
using namespace std;


typedef struct {
    double* w_begin;
    double* w_end;
    int wSize;
    double sum;
} Solution;

Solution* solutionCreate(int* w, int wSize) {
    Solution* solu = (Solution*)malloc(sizeof(Solution));
    double sum = 0.0;
    for(int i = 0; i < wSize; ++i) {
        sum += w[i];
    }
    solu->sum = sum;
    solu->w_begin = (double*)malloc(sizeof(double) * wSize);
    solu->w_end = (double*)malloc(sizeof(double) * wSize);
    solu->w_begin[0] = 0.0;
    solu->w_end[0] = (w[0] * 1.0) / sum;
    for(int i = 1; i < wSize; ++i) {
        solu->w_begin[i] = solu->w_end[i - 1];
        solu->w_end[i] = solu->w_begin[i] + (w[i] * 1.0) / sum;
    }
    solu->wSize = wSize;
    return solu;
}

int solutionPickIndex(Solution* obj) {
    // double randNum = fmod(rand() * 1.0, (obj->w_end[obj->wSize - 1]));
    double randNum = (double)rand()/RAND_MAX;
        // printf("%lf\n", randNum);
    for(int i = 0; i < obj->wSize; ++i) {
        // printf("%lf ", obj->w_begin[i]);
        // printf("%lf\n", obj->w_end[i]);
    
        if(randNum>=obj->w_begin[i] && randNum<obj->w_end[i]) {
            return i;
        }
    }
    return 0;
}

void solutionFree(Solution* obj) {
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(w, wSize);
 * int param_1 = solutionPickIndex(obj);
 
 * solutionFree(obj);
*/