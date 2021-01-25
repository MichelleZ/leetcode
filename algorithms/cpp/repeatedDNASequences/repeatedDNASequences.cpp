// Source: https://leetcode.com/problems/repeated-dna-sequences/
// Author: Miao Zhang
// Date:   2021-01-24

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> visited;
        unordered_set<string> repeated;
        for (int i = 0; i < s.size(); i++) {
            string cur = s.substr(i, 10);
            if (visited.find(cur) != visited.end()) {
                repeated.insert(cur);
            } else {
                visited.insert(cur);
            }
        }
        return vector<string>(repeated.begin(), repeated.end());
    }
};
