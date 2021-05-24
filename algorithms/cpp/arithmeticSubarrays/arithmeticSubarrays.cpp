// Source: https://leetcode.com/problems/arithmetic-subarrays/
// Author: Miao Zhang
// Date:   2021-05-24

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res(l.size(), true);
        for (int i = 0; i < l.size(); i++) {
            vector<int> arr(begin(nums) + l[i], begin(nums) + r[i] + 1);
            sort(begin(arr), end(arr));
            int d = arr[1] - arr[0];
            for (int j = 2; j < arr.size(); j++) {
                res[i] = res[i] && (arr[j] - arr[j - 1] == d);
            }
        }
        return res;
    }
};
