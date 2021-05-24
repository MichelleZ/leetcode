// Source: https://leetcode.com/problems/sort-array-by-increasing-frequency/
// Author: Miao Zhang
// Date:   2021-05-24

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int& num: nums) cnt[num]++;
        sort(nums.begin(), nums.end(), [&cnt] (int a, int b) {
           return (cnt[a] == cnt[b]) ? a > b : cnt[a] < cnt[b];
        });
        return nums;
    }
};
