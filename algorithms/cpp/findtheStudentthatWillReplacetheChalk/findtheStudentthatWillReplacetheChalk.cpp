// Source: https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/
// Author: Miao Zhang
// Date:   2021-06-17

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        int remain = k % accumulate(begin(chalk), end(chalk), 0LL);
        for (int i = 0; i < n; i++) {
            remain -= chalk[i];
            if (remain < 0) return i;
        }
        return -1;
    }
};
