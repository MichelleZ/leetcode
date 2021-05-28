// Source: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
// Author: Miao Zhang
// Date:   2021-05-28

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        vector<int> cnt(2);
        for (int i = 0; i < n; i++) {
            cnt[students[i]]++;
        }
        for (int i = 0; i < n; i++) {
            if (--cnt[sandwiches[i]] < 0) return n - i;
        }
        return 0;
    }
};
