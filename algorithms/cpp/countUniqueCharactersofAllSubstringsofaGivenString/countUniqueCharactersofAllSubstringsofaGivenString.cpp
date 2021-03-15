// Source: https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/
// Author: Miao Zhang
// Date:   2021-03-15

class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<int, vector<int>> idx;
        for (int i = 0; i < s.size(); i++) {
            idx[s[i]].push_back(i);
        }
        int res = 0;
        unordered_map<int, vector<int>>::iterator iter;
        iter = idx.begin();
        while (iter != idx.end()) {
            vector<int> v = iter->second;
            v.insert(v.begin(), -1);
            v.push_back(s.size());
            for (int i = 1; i < v.size() - 1; i++) {
                res += (v[i] - v[i - 1]) * (v[i + 1] - v[i]);
            }
            iter++;
        }
        return res;
    }
};
