// Source: https://leetcode.com/problems/add-strings/
// Author: Miao Zhang
// Date:   2021-02-09

class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.size() < num2.size()) swap(num1, num2);
        num1 = "0" + num1;
        int n1 = num1.size();
        int n2 = num2.size();
        for (int i = 0; i < n1 - 1; i++) {
            if (i < n2) {
                num1[n1 - 1 - i] += (num2[n2 - 1 - i] - '0');
            }
            if (num1[n1 - 1 - i] > '9') {
                    num1[n1 - 1 - i] -= 10;
                    num1[n1 - 1 - i - 1]++;
            }
        }
        return (num1[0] != '0') ? num1: num1.substr(1);
    }
};
