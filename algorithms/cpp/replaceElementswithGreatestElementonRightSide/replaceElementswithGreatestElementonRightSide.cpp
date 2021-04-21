// Source: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
// Author: Miao Zhang
// Date:   2021-04-21

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int g = -1;
        for (int i = arr.size() - 1; i >= 0; i--) {
            g = max(g, exchange(arr[i], g));
        }
        return arr;
    }
};
