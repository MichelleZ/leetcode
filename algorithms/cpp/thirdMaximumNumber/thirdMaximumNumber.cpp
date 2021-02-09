// Source: https://leetcode.com/problems/third-maximum-number/
// Author: Miao Zhang
// Date:   2021-02-09

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (int n: nums) {
            s.insert(n);
            if (s.size() > 3) s.erase(s.begin());
        }
        return s.size() < 3 ? *s.rbegin() : *s.begin();  
    }
};
