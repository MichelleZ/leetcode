// Source: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/
// Author: Miao Zhang
// Date:   2021-05-08

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> t(1001);
        vector<int> a(1001);
        for (int i = 0; i < target.size(); i++) {
            t[target[i]]++;
            a[arr[i]]++;
        }
        return t == a;
    }
};
