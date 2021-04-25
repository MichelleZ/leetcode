// Source: https://leetcode.com/problems/rank-transform-of-an-array/
// Author: Miao Zhang
// Date:   2021-04-24

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s(begin(arr), end(arr));
        unordered_map<int, int> m;
        int rank = 0;
        for (int c: s) m[c] = ++rank;
        vector<int> res(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            res[i] = m[arr[i]];
        }
        return res;
    }
};
