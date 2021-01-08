// Source: https://leetcode.com/problems/trapping-rain-water/
// Author: Miao Zhang
// Date:   2021-01-08

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        stack<pair<int, int>> st;
        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && st.top().first < height[i]) {
                pair<int, int> bottom(st.top().first, st.top().second);
                st.pop();
                while (!st.empty() && st.top().first == bottom.first) {
                    st.pop();
                }
                if (!st.empty()) {
                    res += (min(st.top().first, height[i]) - bottom.first) * (i - st.top().second - 1);
                }
            }
            st.push(pair<int, int>(height[i], i));
        }
        return res;
    }
};
