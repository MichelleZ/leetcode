// Source: https://leetcode.com/problems/verifying-an-alien-dictionary/
// Author: Miao Zhang
// Date:   2021-03-28

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<char> m(26);
        for (int i = 0; i < 26; i++) {
            m[order[i] - 'a'] = 'a' + i;
        }
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].length(); j++) {
                words[i][j] = m[words[i][j] - 'a'];
            }
            if (i > 0 && words[i] < words[i - 1]) return false;
        }
        return true;
    }
};
