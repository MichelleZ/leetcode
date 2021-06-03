// Source: https://leetcode.com/problems/maximum-score-from-removing-stones/
// Author: Miao Zhang
// Date:   2021-06-03

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        array<int, 3> num{a, b, c};
        sort(num.begin(), num.end());
        return (num[0] + num[1] + min(num[0] + num[1], num[2])) / 2;
    }
};
