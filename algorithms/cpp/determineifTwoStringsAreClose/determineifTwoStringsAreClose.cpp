// Source: https://leetcode.com/problems/determine-if-two-strings-are-close/
// Author: Miao Zhang
// Date:   2021-05-26

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        if (l1 != l2) return false;
        vector<int> cnt1(26), cnt2(26);
        vector<int> set1(26), set2(26);
        for (char c: word1) cnt1[c - 'a']++, set1[c - 'a'] = 1;
        for (char c: word2) cnt2[c - 'a']++, set2[c - 'a'] = 1;
        sort(begin(cnt1), end(cnt1));
        sort(begin(cnt2), end(cnt2));
        return cnt1 == cnt2 && set1 == set2;
    }
};
