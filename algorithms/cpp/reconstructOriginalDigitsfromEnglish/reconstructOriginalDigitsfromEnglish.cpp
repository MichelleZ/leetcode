// Source: https://leetcode.com/problems/reconstruct-original-digits-from-english/
// Author: Miao Zhang
// Date:   2021-02-10

/*********************************************************
 * zero: z, two: w, four: u, six: x, eight: g
 * one: o (two, four,zero)
 * three: h(eight)
 * five: f(four)
 * seven: s(six)
 * nine: i(five, six, eight)
*********************************************************/
class Solution {
public:
    string originalDigits(string s) {
        string res = "";
        vector<int> counts(128, 0);
        for (char c: s) counts[c]++;
        vector<int> nums(10, 0);
        nums[0] = counts['z'];
        nums[2] = counts['w'];
        nums[4] = counts['u'];
        nums[6] = counts['x'];
        nums[8] = counts['g'];
        nums[1] = counts['o'] - nums[0] - nums[2] - nums[4];
        nums[3] = counts['h'] - nums[8];
        nums[5] = counts['f'] - nums[4];
        nums[7] = counts['s'] - nums[6];
        nums[9] = counts['i'] - nums[5] - nums[6] - nums[8];
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i]; j++) {
                res += (i + '0');
            }
        }
        return res;
    }
};
