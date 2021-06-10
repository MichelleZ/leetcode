// Source: https://leetcode.com/problems/check-if-the-sentence-is-pangram/
// Author: Miao Zhang
// Date:   2021-06-10

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> s;
        for (char& c: sentence) s.insert(c);
        return s.size() == 26;
    }
};
