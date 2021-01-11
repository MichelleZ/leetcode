// Source: https://leetcode.com/problems/multiply-strings/
// Author: Miao Zhang
// Date:   2021-01-09

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" or num2 == "0") return "0";
        
        int n1 = num1.size(), n2 = num2.size();
        vector<int> res(n1 + n2, 0);
        for (int i = num1.size() - 1; i >= 0; i--) {
            int a = num1[i] - '0';
            for (int j = num2.size() - 1; j >= 0; j--) {
                int b = num2[j] - '0';
                int c = res[i + j + 1] + a * b;
                cout << c << endl;
                res[i + j] += c / 10;
                res[i + j + 1] = c % 10;
            }
        }
        string ans;
        for (int i = 0; i < res.size(); i++) {
            if (i == 0 and res[i] == 0) continue;
            ans += res[i] + '0';
        }
        return ans;
    }
};
