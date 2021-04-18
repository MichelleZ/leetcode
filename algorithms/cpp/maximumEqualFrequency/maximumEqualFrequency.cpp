// Source: https://leetcode.com/problems/maximum-equal-frequency/
// Author: Miao Zhang
// Date:   2021-04-18

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        vector<int> cnt(100001);
        vector<int> freq(100001);

        for (auto n: nums) {
            cnt[n]++;
            freq[cnt[n]]++;
        }
        for (int i = nums.size() - 1; i > 0; i--) {
            if (cnt[nums[i]] * freq[cnt[nums[i]]] == i)
                return i + 1;
            freq[cnt[nums[i]]]--;
            cnt[nums[i]]--;
            if (cnt[nums[i - 1]] * freq[cnt[nums[i - 1]]] == i)
                return i + 1;

        }
        return 1;
    }
};
