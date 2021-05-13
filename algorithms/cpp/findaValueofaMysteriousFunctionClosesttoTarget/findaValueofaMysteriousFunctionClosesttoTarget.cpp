// Source: https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/
// Author: Miao Zhang
// Date:   2021-05-13

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int res = abs(arr[0] - target);
        vector<int> valid = {arr[0]};
        for (int num: arr) {
            vector<int> validNew = {num};
            res = min(res, abs(num - target));
            for (int prev: valid) {
                validNew.push_back(prev & num);
                res = min(res, abs((prev & num) - target));
            }
            validNew.erase(unique(validNew.begin(), validNew.end()), validNew.end());
            valid = validNew;
        }
        return res;
    }
};
