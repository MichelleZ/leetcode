// Source: https://leetcode.com/problems/check-array-formation-through-concatenation/
// Author: Miao Zhang
// Date:   2021-05-24

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> dic;
        for (int i = 0; i < pieces.size(); i++) {
            dic[pieces[i][0]] = i;
        }
        vector<int> res;
        for (int a: arr) {
            if (!dic.count(a)) continue;
            res.insert(end(res), begin(pieces[dic[a]]), end(pieces[dic[a]]));
        }
        return res == arr;
    }
};
