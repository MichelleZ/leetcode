// Source: https://leetcode.com/problems/implement-queue-using-stacks/
// Author: Miao Zhang
// Date:   2021-01-28

class MyQueue {
public:
    stack<int> st;
    stack<int> tmp;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while (!st.empty()) {
            tmp.push(st.top());
            st.pop();
        }
        tmp.push(x);
        while (!tmp.empty()) {
            st.push(tmp.top());
            tmp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = -1;
        if (!st.empty()) {
            val = st.top();
            st.pop();
        }
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        if (!st.empty()) {
            return st.top();
        } else {
            return -1;
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st.empty();
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
