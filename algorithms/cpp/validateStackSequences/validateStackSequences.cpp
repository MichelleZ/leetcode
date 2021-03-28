// Source: https://leetcode.com/problems/validate-stack-sequences/
// Author: Miao Zhang
// Date:   2021-03-28

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        auto it = begin(popped);
        for (auto& p: pushed) {
            st.push(p);
            while (!st.empty() && st.top() == *it) {
                st.pop();
                it++;
            }
        }
        return it == end(popped);
    }
};
