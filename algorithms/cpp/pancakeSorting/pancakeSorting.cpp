// Source: https://leetcode.com/problems/pancake-sorting/
// Author: Miao Zhang
// Date:   2021-03-29

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> res;
        for (int i = 0; i < n - 1; i++) {
            int p = max_element(begin(arr), end(arr) - i) - begin(arr);
            res.push_back(p + 1);
            std::reverse(begin(arr), begin(arr) + p + 1);
            res.push_back(n - i);
            std::reverse(begin(arr), begin(arr) + n - i);
        }
        return res;
    }
};
