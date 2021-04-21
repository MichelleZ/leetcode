// Source: https://leetcode.com/problems/sequential-digits/
// Author: Miao Zhang
// Date:   2021-04-21

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for (int i = 1; i < 10; i++) {
            int num = i;
            for (int j = i + 1; j < 10; j++) {
                num = num * 10 + j;
                if (num >= low && num <= high) {
                    res.push_back(num);
                }
                if (num >= high) break;
            }
        }
        sort(begin(res), end(res));
        return  res;
    }
};
