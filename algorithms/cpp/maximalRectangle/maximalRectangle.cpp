// Source: https://leetcode.com/problems/maximal-rectangle/
// Author: Miao Zhang
// Date:   2021-01-14

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        vector<int> heights(matrix[0].size() + 1, 0);
        int res = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1: 0;
            }
            stack<int> st;
            for (int j = 0; j < heights.size(); j++) {
                if (st.empty() || heights[j] >= heights[st.top()]) {
                    st.push(j);
                } else {
                    while (!st.empty() && heights[j] < heights[st.top()]) {
                        int h = heights[st.top()];
                        st.pop();
                        int w = (st.empty()) ? j : j - st.top() - 1;
                        cout << w << ',';
                        res = max(res, h * w);
                        cout << res << endl;
                    }
                    st.push(j);
                }
            }
        }
        return res;
    }
};
