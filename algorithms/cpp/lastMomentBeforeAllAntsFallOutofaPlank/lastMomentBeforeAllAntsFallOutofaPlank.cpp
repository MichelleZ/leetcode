// Source: https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/
// Author: Miao Zhang
// Date:   2021-05-12

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int t1 = left.empty() ? 0 : *max_element(cbegin(left), cend(left));
        int t2 = right.empty() ? 0 : n - *min_element(cbegin(right), cend(right));
        return max(t1, t2);
    }
};
