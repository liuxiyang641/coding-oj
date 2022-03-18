// https://leetcode.com/problems/min-stack/
// 实现基本的栈操作，同时能够在常数时间内返回当前栈的最小值。使用额外的一个栈随时记录最小值即可。

#include<stack>
using namespace std;

class MinStack {
private:
    stack<int> dataSta, minValSta;
public:
    MinStack() {}
    
    void push(int val) {
        dataSta.push(val);
        if(!minValSta.empty()) {
            int currentMinVal = minValSta.top();
            // 注意，下面需要是>=，因为在pop的时候会根据是否弹出的最小值弹出minValSta，如果有多个相同最小值，就会错误的把最小值弹出去
            if(currentMinVal >= val) {
                minValSta.push(val);
            }
        }
        else {
            minValSta.push(val);
        }
    }
    
    void pop() {
        int topVal = dataSta.top();
        if(topVal == minValSta.top()) {
            minValSta.pop();
        }
        dataSta.pop();
    }
    
    int top() {
        return dataSta.top();
    }
    
    int getMin() {
        return minValSta.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */