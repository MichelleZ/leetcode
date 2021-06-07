// Source: https://leetcode.com/problems/count-items-matching-a-rule/
// Author: Miao Zhang
// Date:   2021-06-07

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
         return count_if(begin(items), end(items), [&] (const auto& item) {
            return (ruleKey == "type" && item[0] == ruleValue
                 || ruleKey == "color" && item[1] == ruleValue
                 || ruleKey == "name" && item[2] == ruleValue);
        });
    }
};
