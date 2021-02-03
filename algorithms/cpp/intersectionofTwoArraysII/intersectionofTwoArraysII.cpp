// Source: https://leetcode.com/problems/intersection-of-two-arrays-ii/
// Author: Miao Zhang
// Date:   2021-02-03

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count;
        vector<int> res;
        for (int &n: nums1) {
            count[n]++;
        }
        for (int n: nums2) {
            if (count.count(n) && count[n] > 0) {
                count[n]--;
                res.push_back(n);
            }
        }
        return res;
    }
};
