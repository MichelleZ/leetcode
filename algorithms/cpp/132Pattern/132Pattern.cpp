// Source: https://leetcode.com/problems/132-pattern/
// Author: Miao Zhang
// Date:   2021-02-13

/******************************************************
 * 132 pattern
 * stack store second part
 * third store third part
******************************************************/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int third = INT_MIN;
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < third) return true;
            while (!st.empty() && nums[i] > st.top()) {
                third = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
