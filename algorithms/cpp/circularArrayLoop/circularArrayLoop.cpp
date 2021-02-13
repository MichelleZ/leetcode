// Source: https://leetcode.com/problems/circular-array-loop/
// Author: Miao Zhang
// Date:   2021-02-13

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int slow = i;
            int fast = getNext(nums, i);
            while (nums[fast] * nums[i] > 0 && nums[getNext(nums, fast)] * nums[i] > 0) {
                if (fast == slow) {
                    if (slow == getNext(nums, slow)) break;
                    return true;
                }
                slow = getNext(nums, slow);
                fast = getNext(nums, getNext(nums, fast));
            }
        }
        return false;
    }

private:
    int getNext(vector<int>& nums, int index) {
        int n = nums.size();
        return ((index + nums[index]) % n + n) % n;
    }
};
