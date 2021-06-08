// Source: https://leetcode.com/problems/second-largest-digit-in-a-string/
// Author: Miao Zhang
// Date:   2021-06-08

class Solution {
public:
    int secondHighest(string s) {
        int first = INT_MIN;
        int second = INT_MIN;
        for (char c: s) {
            if (c >= '0' && c <= '9') {
                int num = c - '0';
                if (num > first) {
                    second = first;
                    first = num;
                } else if (num > second) {
                    second = num == first ? second : num;
                }
            }
        }
        return second == INT_MIN ? -1 : second;
    }
};
