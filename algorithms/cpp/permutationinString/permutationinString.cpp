// Source: https://leetcode.com/problems/permutation-in-string/
// Author: Miao Zhang
// Date:   2021-02-23

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        vector<int> c1(26);
        vector<int> c2(26);
        for (const char c: s1) c1[c - 'a']++;
        for (int i = 0; i < n2; i++) {
            if (i >= n1) {
                c2[s2[i - n1] - 'a']--;
            }
            c2[s2[i] - 'a']++;
            if (c1 == c2) return true;
        }
        return false;
    }
};
