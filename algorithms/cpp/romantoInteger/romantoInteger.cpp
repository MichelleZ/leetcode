// Source: https://leetcode.com/problems/roman-to-integer/
// Author: Miao Zhang
// Date:   2021-01-05

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> s2v{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for (int i = 0; i < s.size(); i++) {
            int val = s2v[s[i]];
            if (i == s.size() - 1 || s2v[s[i + 1]] <= val) {
                res += val;
            } else {
                res -= val;
            }
        }
        
        return res;
    }
};
