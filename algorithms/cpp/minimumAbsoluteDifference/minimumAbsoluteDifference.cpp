// Source: https://leetcode.com/problems/minimum-absolute-difference/
// Author: Miao Zhang
// Date:   2021-04-16

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(begin(arr), end(arr));
        vector<vector<int>> res;
        int best = INT_MAX;
        for (int i = 1; i < arr.size(); i++) {
            int tmp = arr[i] - arr[i - 1];
            if (tmp < best) {
                best = tmp;
                res.clear();
            }
            if (tmp == best)
                res.push_back({arr[i - 1], arr[i]});
        }
        return res;
    }
};
