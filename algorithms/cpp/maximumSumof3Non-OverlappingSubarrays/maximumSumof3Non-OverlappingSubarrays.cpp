// Source: https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/
// Author: Miao Zhang
// Date:   2021-03-01

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> kintervals(n - k + 1, 0);
        
        int sums = 0;
        for (int i = 0; i < n; i++) {
            sums += nums[i];
            if (i >= k) sums -= nums[i - k];
            if (i >= k - 1) kintervals[i - k + 1] = sums;
        }
        
        vector<int> left(kintervals.size(), 0);
        int best = 0;
        for (int i = 0; i < kintervals.size(); i++) {
            if (kintervals[i] > kintervals[best]) best = i;  // > means lexicographically 
            left[i] = best;
        }
        
        vector<int> right(kintervals.size(), 0);
        best = kintervals.size() - 1;
        for (int i = kintervals.size() - 1; i >= 0; i--) {
            if (kintervals[i] >= kintervals[best]) best = i; // >= means lexicographically
            right[i] = best;
        }
        for (auto r: right) cout << r << ",";
        cout << endl;
        // i + k <= j, j + k <= m
        // i, j, m
        vector<int> res{-1, -1, -1};
        for (int j = k; j < kintervals.size() - k; j++) {
            int i = left[j - k], m = right[j + k];
            if (res[0] == -1 || kintervals[i] + kintervals[j] + kintervals[m] >
               kintervals[res[0]] + kintervals[res[1]] + kintervals[res[2]]) {
                res[0] = i;
                res[1] = j;
                res[2] = m;
            } 
        }
        return res;
    }
};
