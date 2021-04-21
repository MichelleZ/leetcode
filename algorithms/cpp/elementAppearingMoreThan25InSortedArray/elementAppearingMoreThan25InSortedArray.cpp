// Source: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
// Author: Miao Zhang
// Date:   2021-04-21

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int t = arr.size() / 4;
        for (int i = 0; i + t < arr.size(); i++) {
            if (arr[i] == arr[i + t]) return arr[i];
        }
        return -1;
    }
};
