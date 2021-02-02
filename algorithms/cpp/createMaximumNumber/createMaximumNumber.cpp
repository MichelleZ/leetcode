// Source: https://leetcode.com/problems/create-maximum-number/
// Author: Miao Zhang
// Date:   2021-02-02

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for (int k1 = 0; k1 <= k; k1++) {
            int k2 = k - k1;
            if (k1 > n1 || k2 > n2) continue;
            res = max(res, maxNumber(maxNumber(nums1, k1), 
                                     maxNumber(nums2, k2)));
        }
        return res;
    }

private:
    vector<int> maxNumber(vector<int>& nums, int k) {
        if (k == 0) return {};
        vector<int> res;
        int to_pop = nums.size() - k;
        for (const int num: nums) {
            while (!res.empty() && num > res.back() && to_pop-- > 0) {
                res.pop_back();
            }
            res.push_back(num);
        }
        res.resize(k);
        return res;
    }
    
    vector<int> maxNumber(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> res;
        auto s1 = nums1.cbegin();
        auto e1 = nums1.cend();
        auto s2 = nums2.cbegin();
        auto e2 = nums2.cend();
        while (s1 != e1 || s2 != e2) {
            res.push_back(
                lexicographical_compare(s1, e1, s2, e2) ? *s2++ : *s1++);
        }
        return res;
    }
};
