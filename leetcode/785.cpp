// https://leetcode.com/problems/is-graph-bipartite/
// 判断一个graph是不是二分图，即所有的节点可以分到两个集合中，图的所有边都是连接两个集合中的节点
// 从某个节点出发，划分到集合1，则它的所有邻居都必须在集合2，如果发生冲突，就报错；如果邻居都能够放到集合2，则继续从邻居节点出发


#include<algorithm>
using namespace std;

bool isBipartite(int** graph, int graphSize, int* graphColSize){
    int* belongTo = (int*)malloc(sizeof(int) * graphSize);
    for(int i = 0; i < graphSize; ++i) {
        belongTo[i] = -1;
    }
    int* queue = (int*)malloc(sizeof(int) * graphSize);
    int queueLen = 0;
    // 保证访问所有的节点
    for(int node = 0; node < graphSize; ++node) {
        if(belongTo[node] == -1) {
            belongTo[node] = 0;
            queue[queueLen++] = node;
            while (queueLen) {
                int* tmpQueue = (int*)malloc(sizeof(int) * graphSize);
                int tmpLen = 0;
                while (queueLen) {
                    int top = queue[--queueLen];
                    int neighBelongTo = belongTo[top] == 0 ? 1 : 0;
                    for(int i = 0; i < graphColSize[top]; ++i) {
                        int neigh = graph[top][i];
                         // 如果是首次访问
                        if(belongTo[neigh] == -1) {
                                belongTo[neigh] = neighBelongTo;
                                tmpQueue[tmpLen++] = neigh;
                        }
                        else if(belongTo[neigh] != neighBelongTo) {
                            // 如果不是首次访问，并且发生了之前属于的集合和当前的希望集合冲突
                            return false;
                        }
                    }
                }
                // 把下一层的节点再作为出发的根结点
                while (tmpLen) {
                    queue[queueLen++] = tmpQueue[--tmpLen];
                }
            }
        }
    }
    return true;   
}