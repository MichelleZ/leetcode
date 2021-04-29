// Source: https://leetcode.com/problems/count-number-of-teams/
// Author: Miao Zhang
// Date:   2021-04-29

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int res = 0;
        for (int j = 0; j < n; j++) {
            int l = 0;
            int r = 0;
            for (int i = 0; i < j; i++) {
                if (rating[i] < rating[j]) l++;
            }
            for (int k = j + 1; k < n; k++) {
                if (rating[k] > rating[j]) r++;
            }
            res += (l * r) + (j - l) * (n - 1 - j - r);
        }
        return res;
    }
};
