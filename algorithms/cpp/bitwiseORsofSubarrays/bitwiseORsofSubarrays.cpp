// Source: https://leetcode.com/problems/bitwise-ors-of-subarrays/
// Author: Miao Zhang
// Date:   2021-03-23

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res;
        unordered_set<int> cur;
        unordered_set<int> nxt;
        for (int a: arr) {
            nxt.clear();
            nxt.insert({a});
            for (int b: cur) {
                nxt.insert(a | b);
            }
            cur.swap(nxt);
            res.insert(begin(cur), end(cur));
        } 
        return res.size();
    }
};
