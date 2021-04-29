// Source: https://leetcode.com/problems/count-largest-group/
// Author: Miao Zhang
// Date:   2021-04-29

class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> cnt(37); // max: 9 + 9 + 9 + 9
        for (int i = 1; i <= n; i++) {
            int sum = 0;
            int x = i;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            cnt[sum]++;
        }
        return count(begin(cnt), end(cnt), *max_element(begin(cnt), end(cnt)));
    }
};
