// Source: https://leetcode.com/problems/sort-an-array/
// Author: Miao Zhang
// Date:   2021-03-24

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        function<void(int, int)> quickSort = [&](int l, int r) {
            if (l >= r) return;
            int i = l;
            int j = r;
            int pivot = nums[l + rand() % (r - l + 1)];
            while (i <= j) {
                while (nums[i] < pivot) i++;
                while (nums[j] > pivot) j--;
                if (i <= j) {
                    swap(nums[i++], nums[j--]);
                }
            }
            quickSort(l, j);
            quickSort(i, r);
        };
        quickSort(0, nums.size() - 1);
        return nums;
    }
};
