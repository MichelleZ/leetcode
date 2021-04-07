// Source: https://leetcode.com/problems/previous-permutation-with-one-swap/
// Author: Miao Zhang
// Date:   2021-04-07

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int maxval = 0;
        int idx = -1;
        for (int i = n - 1; i > 0; i--) {
            if (arr[i] >= arr[i - 1]) continue;
            for (int j = i; j < n; j++) {
                if (arr[j] < arr[i - 1] && maxval < arr[j]) {
                    maxval = arr[j];
                    idx = j;
                }
            }
            swap(arr[i- 1], arr[idx]);
            break;
        }
        return arr;
    }
};
