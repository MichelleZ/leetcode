// Source: https://leetcode.com/problems/longest-repeating-character-replacement/
// Author: Miao Zhang
// Date:   2021-02-10

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> dic;
        int left = 0;
        int max_num = 0;
        for (int i = 0; i < s.size(); i++) {
            dic[s[i]] += 1;
            max_num = max(max_num, dic[s[i]]);
            if (i - left + 1 > max_num + k) {
                dic[s[left]]--;
                left++;
            }
        }
        return s.size() - left;
    }
};
