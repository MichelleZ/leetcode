// Source: https://leetcode.com/problems/intersection-of-two-arrays/
// Author: Miao Zhang
// Date:   2021-02-03

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersection(max(nums1.size(), nums2.size()));
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto it = set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), intersection.begin());
        intersection.resize(it - intersection.begin());
        set<int> s(intersection.begin(), intersection.end());
        return vector<int>(s.begin(), s.end());
    }
};
