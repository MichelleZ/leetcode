// Source: https://leetcode.com/problems/shuffle-string/
// Author: Miao Zhang
// Date:   2021-05-13

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string res(s);
        for (int i = 0; i < s.length(); i++) {
            res[indices[i]] = s[i];
        }
        return res;
    }
};
