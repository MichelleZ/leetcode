// Source: https://leetcode.com/problems/min-stack/
// Author: Miao Zhang
// Date:   2021-01-22

class MinStack {
private:
    stack<int> st;
    stack<int> min;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if (min.empty()) {
            min.push(x);
        } 
        else {
            min.push(x < min.top() ? x : min.top());
        }
    }
    
    void pop() {
        st.pop();
        min.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
