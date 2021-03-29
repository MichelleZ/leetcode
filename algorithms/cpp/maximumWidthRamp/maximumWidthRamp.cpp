// Source: https://leetcode.com/problems/maximum-width-ramp/
// Author: Miao Zhang
// Date:   2021-03-29

class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        stack<int> st;
        for (int i = 0; i < A.size(); i++) {
            if (st.empty() || A[i] < A[st.top()]) {
                st.push(i);
            }
        }
        int res = 0;
        for (int i = A.size() - 1; i >= 0; i--) {
            while (!st.empty() && A[i] >= A[st.top()]) {
                res = max(res, i - st.top());
                st.pop();
            }
        }
        return res;
    }
};
