// Source: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Author: Miao Zhang
// Date:   2021-01-24

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < numbers.size(); i++) {
            if (m.find(numbers[i]) != m.end()) {
                return {m[numbers[i]], i + 1};
            }
            m[target - numbers[i]] = i + 1;
        }
        return {-1, -1};
    }
};
