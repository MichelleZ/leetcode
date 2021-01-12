// Source: https://leetcode.com/problems/group-anagrams/
// Author: Miao Zhang
// Date:   2021-01-12

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dicts;
        vector<vector<string>> res;
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            dicts[str].push_back(strs[i]);
        }
        for (auto d: dicts) {
            res.push_back(d.second);
        }
        return res;
    }
};
