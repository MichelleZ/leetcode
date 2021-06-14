// Source: https://leetcode.com/problems/maximum-subarray-min-product/
// Author: Miao Zhang
// Date:   2021-06-14

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int kMod = 1e9 + 7;
        int n = nums.size();
        vector<int> left(n), right(n, n - 1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                right[st.top()] = i - 1;
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top() + 1;
            }
            st.push(i);
        }

        vector<long long> sums(n + 1);
        for (int i = 1; i < n + 1; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, (sums[right[i] + 1] - sums[left[i]]) * nums[i]);
        }
        return res % kMod;
    }
};
