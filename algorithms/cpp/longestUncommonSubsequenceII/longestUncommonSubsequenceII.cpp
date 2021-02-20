// Source: https://leetcode.com/problems/longest-uncommon-subsequence-ii/
// Author: Miao Zhang
// Date:   2021-02-19

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int res = -1;
        int n = strs.size();
        for (int i = 0; i < n; i++) {
            bool is_flag = false;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (check(strs[i], strs[j])) {
                    is_flag = true;
                    break;
                }
            }
            if (!is_flag) res = max(res, (int)strs[i].size());
        }
        return res;
    }

    bool check(string str1, string str2) {
        int i = 0;
        for (int j = 0; j < str2.size(); j++) {
            if (str1[i] == str2[j]) i++;
            if (i == str1.size()) break;
        }
        return i == str1.size();
    }
};
