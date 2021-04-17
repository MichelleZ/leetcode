// Source: https://leetcode.com/problems/get-equal-substrings-within-budget/
// Author: Miao Zhang
// Date:   2021-04-17

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int res = 0;
        int left = 0;
        int right = 0;
        int cost = 0;
        while (right < n) {
            int c = abs(s[right] - t[right]);
            cost += c;
            while (left <= right && cost > maxCost) {
                cost -= abs(s[left] - t[left]);
                left++;
            }
            if (cost <= maxCost)
                res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};
