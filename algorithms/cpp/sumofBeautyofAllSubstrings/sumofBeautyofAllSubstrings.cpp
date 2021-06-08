// Source: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
// Author: Miao Zhang
// Date:   2021-06-07

class Solution {
public:
    int beautySum(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            vector<int> cnt(26);
            for (int j = i; j < s.size(); j++) {
                cnt[s[j] - 'a']++;
                res = res + beauty(cnt);
            }
        }
        return res;
    }

private:
    int beauty(vector<int>& cnt) {
        int maxf = INT_MIN;
        int minf = INT_MAX;
        for (int i = 0; i < cnt.size(); i++) {
            maxf = max(maxf, cnt[i]);
            if (cnt[i] >= 1)
                minf = min(minf, cnt[i]);
        }
        return maxf - minf;
    }
};
