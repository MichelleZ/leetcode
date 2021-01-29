// Source: https://leetcode.com/problems/different-ways-to-add-parentheses/
// Author: Miao Zhang
// Date:   2021-01-28

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for (auto l: left) {
                    for (auto r: right) {
                        if (input[i] == '+') {
                            res.push_back(l + r);
                        } else if (input[i] == '-') {
                            res.push_back(l - r);
                        } else {
                            res.push_back(l * r);
                        }
                    }
                }
            }
        }
        
        if (res.empty()) {
            int num = 0;
            for (auto c: input) {
                num = num * 10 + c - '0';
            }
            res.push_back(num);
        }
        return res;
    }
};
