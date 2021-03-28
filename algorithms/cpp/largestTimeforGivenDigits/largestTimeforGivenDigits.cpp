// Source: https://leetcode.com/problems/largest-time-for-given-digits/
// Author: Miao Zhang
// Date:   2021-03-28

class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        string res;
        sort(arr.begin(), arr.end());
        do {
            string hour = {char(arr[0] + '0'), char(arr[1] + '0')};
            string min = {char(arr[2] + '0'), char(arr[3] + '0')};
            res = (hour <= "23" && min <= "59") ? (hour + ":" + min) : res;
        } while (next_permutation(arr.begin(), arr.end()));
        return res;
    }
};
