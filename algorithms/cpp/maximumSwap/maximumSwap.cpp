// Source: https://leetcode.com/problems/maximum-swap/
// Author: Miao Zhang
// Date:   2021-02-27

class Solution {
public:
    int maximumSwap(int num) {
        string nums = to_string(num);
        unordered_map<int, int> cnt;
        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i] - '0'] = i;
        }
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = 9; j > (nums[i] - '0'); j--) {
                if (cnt.count(j) && cnt[j] > i) {
                    swap(nums[i], nums[cnt[j]]);
                    return atoi(nums.c_str());
                }
            }
        }
        return num;
    }
};
