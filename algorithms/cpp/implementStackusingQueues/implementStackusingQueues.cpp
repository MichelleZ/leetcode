// Source: https://leetcode.com/problems/implement-stack-using-queues/
// Author: Miao Zhang
// Date:   2021-01-27

class MyStack {
private:
    queue<int> q;
    queue<int> tmp;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        tmp.push(x);
        while (!q.empty()) {
            tmp.push(q.front());
            q.pop();
        }
        while (!tmp.empty()) {
            q.push(tmp.front());
            tmp.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (!q.empty()) {
            int val = q.front();
            q.pop();
            return val;
        } else return -1;
    }
    
    /** Get the top element. */
    int top() {
        if (!q.empty()) {
            return q.front();
        } else {
            return -1;
        }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
