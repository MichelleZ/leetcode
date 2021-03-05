// Source: https://leetcode.com/problems/daily-temperatures/
// Author: Miao Zhang
// Date:   2021-03-05

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        stack<int> st;
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && T[st.top()] <= T[i]) st.pop();
            res[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        return res;
    }
};
