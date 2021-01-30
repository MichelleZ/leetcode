// Source: https://leetcode.com/problems/expression-add-operators/
// Author: Miao Zhang
// Date:   2021-01-30

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        for (int i = 1; i <= num.size(); i++) {
            if (i == 1 || (i > 1 && num[0] != '0')) {
                string num1 = num.substr(0, i);
                string num2 = num.substr(i);
                dfs(num2, num1, stoll(num1), stoll(num1), res, target);
            }
        }
        return res;
    }
    
    void dfs(string num, string path, long long cur, long long last, 
             vector<string>& res, int target) {
        if (num.empty()) {
            if (cur == target) {
                res.push_back(path);
                return;
            }
        }
        for (int i = 1; i <= num.size(); i++) {
            string num1 = num.substr(0, i);
            string num2 = num.substr(i);
            if (i == 1 || (i > 1 && num[0] != '0')) {
                dfs(num2, path + "+" + num1, cur + stoll(num1), 
                    stoll(num1), res, target);
                dfs(num2, path + "-" + num1, cur - stoll(num1), 
                    -stoll(num1), res, target);
                dfs(num2, path + "*" + num1, cur - last + last * stoll(num1), 
                    last * stoll(num1), res, target);
                
            }
        }
    }
};
