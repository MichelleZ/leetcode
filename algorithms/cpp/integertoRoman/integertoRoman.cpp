// Source: https://leetcode.com/problems/integer-to-roman/
// Author: Miao Zhang
// Date:   2021-01-05

class Solution {
public:
    string intToRoman(int num) {
        vector<string> symbol = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> value = {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1};
        string res;
        
        for (int i = 0; num != 0; i++) {
            while (num >= value[i]) {
                num -= value[i];
                res += symbol[i];
            }
        }
        
        return res;
    }
};
