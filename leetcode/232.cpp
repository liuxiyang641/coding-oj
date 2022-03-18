// https://leetcode.com/problems/implement-queue-using-stacks/
// 使用两个栈来实现队列，一个stack s1用于保存所有push的数据，一个stack s2用于队列的pop操作，s1->s2, s2.pop, s2->s1

#include<stack>
using namespace std;

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        // this->s1.clear();
    }
    
    void push(int x) {
        this->s1.push(x);
    }
    
    int pop() {
        while (!this->s1.empty())
        {
            this->s2.push(this->s1.top());
            this->s1.pop();
        }
        int ans = this->s2.top();
        this->s2.pop();
        while (!this->s2.empty())
        {
            this->s1.push(this->s2.top());
            this->s2.pop();
        }
        return ans;
    }
    
    int peek() {
        while (!this->s1.empty())
        {
            this->s2.push(this->s1.top());
            this->s1.pop();
        }
        int ans = this->s2.top();
        // this->s2.pop();
        while (!this->s2.empty())
        {
            this->s1.push(this->s2.top());
            this->s2.pop();
        }
        return ans;
    }
    
    bool empty() {
        return this->s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */