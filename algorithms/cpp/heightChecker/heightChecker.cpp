// Source: https://leetcode.com/problems/height-checker/
// Author: Miao Zhang
// Date:   2021-04-07

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> h(heights);
        sort(begin(h), end(h));
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            res += (heights[i] != h[i]);
        }
        return res;
    }
};
