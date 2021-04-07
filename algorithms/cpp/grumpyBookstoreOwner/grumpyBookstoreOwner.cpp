// Source: https://leetcode.com/problems/grumpy-bookstore-owner/
// Author: Miao Zhang
// Date:   2021-04-07

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int base = 0;
        int window = 0;
        int best_window = 0;
        for (int i = 0; i < grumpy.size(); i++) {
            (grumpy[i] ? window : base) += customers[i];
            if (i >= X && grumpy[i - X])
                window -= customers[i - X];
            best_window = max(best_window, window);
        }
        return base + best_window;
    }
};
