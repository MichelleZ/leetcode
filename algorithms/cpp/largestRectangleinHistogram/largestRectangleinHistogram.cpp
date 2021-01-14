// Source: https://leetcode.com/problems/largest-rectangle-in-histogram/
// Author: Miao Zhang
// Date:   2021-01-14

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (st.empty() || heights[i] > heights[st.top()]) {
                st.push(i);
            } else {
                while (!st.empty() && heights[i] <= heights[st.top()]) {
                    int h = heights[st.top()];
                    st.pop();
                    int w = (st.empty()) ? i : i - st.top() - 1;
                    res = max(res, h * w);
                }
                st.push(i);
            }
        }
        return res;
    }
};
