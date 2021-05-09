// Source: https://leetcode.com/problems/the-k-strongest-values-in-an-array/
// Author: Miao Zhang
// Date:   2021-05-09

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        int i = (n - 1) / 2;
        nth_element(begin(arr), begin(arr) + i, end(arr));
        int m = arr[i];
        sort(begin(arr), end(arr), [&] (const int x, const int y) {
            return abs(x - m) != abs(y - m) ? abs(x - m) > abs(y - m) : x > y;
        });
        return {begin(arr), begin(arr) + k};
    }
};
