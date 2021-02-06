// Source: https://leetcode.com/problems/shuffle-an-array/
// Author: Miao Zhang
// Date:   2021-02-06

class Solution {
public:
    Solution(vector<int>& nums) {
        nums_ = std::move(nums);
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums_;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> nums(nums_);
        int n = nums_.size();
        for (int i = 0; i < n; i++) {
            int j = rand() % ( n - i) + i;
            swap(nums[i], nums[j]);
        }
        return nums;
    }

private: 
    vector<int> nums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
