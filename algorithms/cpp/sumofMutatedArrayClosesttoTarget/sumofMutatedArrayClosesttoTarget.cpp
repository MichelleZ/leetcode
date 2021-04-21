// Source: https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/
// Author: Miao Zhang
// Date:   2021-04-21

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(begin(arr), end(arr));
        int n = arr.size();
        vector<int> sums(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + arr[i];
        }

        auto check = [&] (int num) {
            int idx = lower_bound(begin(arr), end(arr), num) - begin(arr);
            return sums[idx] + (n - idx) * num;
        };

        int l = 1;
        int r = *max_element(begin(arr), end(arr));
        while (l < r) {
            int m = l + (r - l) / 2;
            if (check(m) > target){
                r = m;
            } else {
                l = m + 1;
            }
        }

        int sum1 = check(l);
        int sum2 = check(l - 1);
        return abs(sum2 - target) <= abs(sum1 - target) ? l - 1 : l;
    }
};
