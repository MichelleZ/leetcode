// Source: https://leetcode.com/problems/longest-common-prefix/
// Author: Miao Zhang
// Date:   2021-01-05

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        
        char* str = (char*) malloc(sizeof(char) * (strs[0].size() + 1));
        for (int i = 0; i < strs[0].size(); i++) {
            str[i] = strs[0][i];
        }
        str[strs[0].size()] = 0;
        
        for (int j = 1; j < strs.size(); j++) {
            int i = 0;
            while (str[i] && strs[j][i] && str[i] == strs[j][i]) {
                i++;
            }
            str[i] = 0;
        }
        
        return string(str);
    }
};
