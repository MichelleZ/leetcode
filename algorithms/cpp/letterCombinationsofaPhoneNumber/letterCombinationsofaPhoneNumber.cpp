// Source: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author: Miao Zhang
// Date:   2021-01-06

/***************************************
 * Use recursion to solve the problem due to length of uncertain string.
 * Variable level is used to record the position of traversal string.
***************************************/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        
        map<char, string> num_map {
            {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, 
            {'5',"jkl"},{'6',"mno"}, {'7',"pqrs"},
            {'8',"tuv"}, {'9',"wxyz"}
        };
        vector<string> res;
        dfs(digits, num_map, 0, "", res);
        return res;
    }
    
    void dfs(string digits, map<char, string> dict_map, int level, string out, vector<string>& res) {
        if (level == digits.size()) {
            res.push_back(out);
            return;
        }
        string str = dict_map[digits[level]];
        for (int i = 0; i < str.size(); i++) {
            dfs(digits, dict_map, level + 1, out + str[i], res);
        }
    }
};

