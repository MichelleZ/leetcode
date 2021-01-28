// Source: https://leetcode.com/problems/majority-element-ii/
// Author: Miao Zhang
// Date:   2021-01-28

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1 = 0;
        int c1 = 0;
        int n2 = 1;
        int c2 = 0;
        for (auto num: nums) {
            if (num == n1) c1++;
            else if (num == n2) c2++;
            else if (c1 == 0) {
                n1 = num;
                c1++;
            } else if (c2 == 0) {
                n2 = num;
                c2++;
            } else {
                c1--;
                c2--;
            }
        }
        c1 = 0;
        c2 = 0;
        for (auto num: nums) {
            if (num == n1) c1++;
            if (num == n2) c2++;
        }
        vector<int> res;
        int n = nums.size() / 3;
        if (c1 > n) res.push_back(n1);
        if (c2 > n) res.push_back(n2);
        return res;
    }
};
