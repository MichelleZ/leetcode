// Source: https://leetcode.com/problems/dinner-plate-stacks/
// Author: Miao Zhang
// Date:   2021-04-15

class DinnerPlates {
public:
    DinnerPlates(int capacity) : cap_(capacity) {

    }

    void push(int val) {
        int idx = index_.empty() ? stacks_.size() : *begin(index_);
        if (idx == stacks_.size()) stacks_.emplace_back();
        stack<int>& s = stacks_[idx];
        s.push(val);
        if (s.size() == cap_) {
            index_.erase(idx);
        } else if (s.size() == 1) {
            index_.insert(idx);
        }
    }

    int pop() {
        return popAtStack(stacks_.size() - 1);
    }

    int popAtStack(int index) {
        if (index < 0 || index >= stacks_.size() || stacks_[index].empty()) return -1;
        stack<int>& s = stacks_[index];
        int val = s.top();
        s.pop();
        if (s.size() == cap_ - 1)
            index_.insert(index);
        auto it = prev(end(index_));
        while (stacks_.size() && stacks_.back().empty()) {
            stacks_.pop_back();
            index_.erase(it--);
        }
        return val;
    }

private:
    int cap_;
    set<int> index_;
    vector<stack<int>> stacks_;
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
