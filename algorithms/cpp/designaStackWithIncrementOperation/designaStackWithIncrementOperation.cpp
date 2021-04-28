// Source: https://leetcode.com/problems/design-a-stack-with-increment-operation/
// Author: Miao Zhang
// Date:   2021-04-28

class CustomStack {
public:
    CustomStack(int maxSize) : maxsize_(maxSize) {

    }

    void push(int x) {
        if (data_.size() == maxsize_) return;
        data_.push_back(x);
    }

    int pop() {
        if (data_.empty()) return -1;
        int val = data_.back();
        data_.pop_back();
        return val;
    }

    void increment(int k, int val) {
        for (int i = 0; i < min(static_cast<size_t>(k), data_.size()); i++) {
            data_[i] += val;
        }
    }

private:
    int maxsize_;
    vector<int> data_;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
