// Source: https://leetcode.com/problems/maximum-frequency-stack/
// Author: Miao Zhang
// Date:   2021-03-22

/***************************************************************
 * freq: val: frequency
 * stacks: {[stack] with frequecy = 1, [stack] with frequency = 2...}
***************************************************************/
class FreqStack {
public:
    FreqStack() {

    }

    void push(int val) {
        auto it = freq.find(val);
        if (it == freq.end()) {
            it = freq.emplace(val, 0).first;
        }
        int freq = ++it->second;
        if (stacks.size() < freq) stacks.push_back({});
        stacks[freq - 1].push(val);
    }

    int pop() {
        int val = stacks.back().top();
        stacks.back().pop();
        if (stacks.back().empty()) {
            stacks.pop_back();
        }
        auto it = freq.find(val);
        if (!(--it->second)) freq.erase(it);
        return val;
    }

private:
    unordered_map<int, int> freq;
    vector<stack<int>> stacks;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
