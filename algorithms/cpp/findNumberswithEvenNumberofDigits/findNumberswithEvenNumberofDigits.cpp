// Source: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
// Author: Miao Zhang
// Date:   2021-04-21

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        return count_if(begin(nums), end(nums), [] (int num) {
            int res = 0;
            while (num) {
                res++;
                num /= 10;
            }
            return res % 2 == 0;
        });
    }
};
