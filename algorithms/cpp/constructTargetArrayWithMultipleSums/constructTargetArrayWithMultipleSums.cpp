// Source: https://leetcode.com/problems/construct-target-array-with-multiple-sums/
// Author: Miao Zhang
// Date:   2021-04-26

class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> q(begin(target), end(target));
        long sums = accumulate(begin(target), end(target), 0LL);
        while (true) {
            int m = q.top();
            q.pop();
            sums -= m;
            if (m == 1) return true; // largest number is 1;
            if (sums == 1) return true; // [1, m]
            if (sums == 0 || sums >= m) return false; // [m] or [1, 1, 2]
            m %= sums;
            if (m == 0) return false;
            sums += m;
            q.push(m);
        }
        return false;
    }
};
