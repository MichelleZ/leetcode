// Source: https://leetcode.com/problems/count-nice-pairs-in-an-array/
// Author: Miao Zhang
// Date:   2021-06-09

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int kMod = 1e9 + 7;
        unordered_map<int, int> m;
        long res = 0;
        for (int num: nums) {
            string s = to_string(num);
            reverse(begin(s), end(s));
            res += m[num - stoi(s)]++;
        }
        return res % kMod;
    }
};
