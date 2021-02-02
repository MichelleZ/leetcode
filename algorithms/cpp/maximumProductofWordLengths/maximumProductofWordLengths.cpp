// Source: https://leetcode.com/problems/maximum-product-of-word-lengths/
// Author: Miao Zhang
// Date:   2021-02-02

class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<string, int> dic;
        int res = 0;
        for (int i = 0; i < words.size(); i++) {
            for (auto c: words[i]) {
                dic[words[i]] |= 1 << (c - 'a');
            }
            for (int j = 0; j < i; j++) {
                if (! (dic[words[i]] & dic[words[j]]) && res < words[i].size() * words[j].size()) {
                    res = words[i].size() * words[j].size();
                }
            }
        }
        return res;
    }
};
