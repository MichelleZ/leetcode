// Source: https://leetcode.com/problems/three-consecutive-odds/
// Author: Miao Zhang
// Date:   2021-05-15

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for (int a: arr) {
            if (a & 1) {
                cnt++;
            } else {
                cnt = 0;
            }
            if (cnt == 3) return true;
        }
        return false;
    }
};
