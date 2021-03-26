// Source: https://leetcode.com/problems/three-equal-parts/
// Author: Miao Zhang
// Date:   2021-03-26

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        string s(begin(arr), end(arr));
        int ones = accumulate(begin(arr), end(arr), 0);
        if (ones % 3 != 0) return {-1, -1};
        if (ones == 0) return {0, (int)arr.size() - 1};
        ones /= 3;
        int right = arr.size() - 1;
        while (ones) if (arr[right--]) ones--;
        string suffix(begin(s) + right + 1, end(s));
        int l = suffix.size();
        int left = s.find(suffix);
        if (left == std::string::npos) return {-1, -1};
        int mid = s.find(suffix, left + l);
        if (mid == std::string::npos || mid + 2 * l > s.size()) {
            return {-1, -1};
        }
        return {left + l - 1, mid + l};
    }
};
