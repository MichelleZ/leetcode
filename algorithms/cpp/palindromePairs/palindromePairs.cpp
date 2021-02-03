// Source: https://leetcode.com/problems/palindrome-pairs/
// Author: Miao Zhang
// Date:   2021-02-03

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> wmap;
        set<vector<int>> res;
        for (int i = 0; i < words.size(); i++) {
            wmap[words[i]] = i;
        }
        
        for (int i = 0; i < words.size(); i++) {
            if (!words[i].empty() && isPalindrome(words[i]) && (wmap.find("") != wmap.end())) {
                int j = wmap[""];
                res.insert({i, j});
                res.insert({j, i});
            }
            
            string rword = words[i];
            reverse(rword.begin(), rword.end());
            if (!words[i].empty() && (wmap.find(rword) != wmap.end())) {
                int j = wmap[rword];
                if (i != j) {
                    res.insert({i, j});
                    res.insert({j, i});
                }
            }
            
            for (int j = 1; j < words[i].size(); j++) {
                string left = words[i].substr(0, j);
                string rleft = left;
                reverse(rleft.begin(), rleft.end());
                string right = words[i].substr(j);
                string rright = right;
                reverse(rright.begin(), rright.end());
                if (isPalindrome(left) && (wmap.find(rright) != wmap.end())) {
                    res.insert({wmap[rright], i});
                }
                if (isPalindrome(right) && (wmap.find(rleft) != wmap.end())) {
                    res.insert({i, wmap[rleft]});
                }
            }
        }
        vector<vector<int>> ress(res.begin(), res.end());
        return ress;
    }

private:
    bool isPalindrome(string word) {
        if (word.size() <= 1) return true;
        int start = 0;
        int end = word.size() - 1;
        while (start < end) {
            if (word[start++] != word[end--]) return false;
        }
        return true;
    }
};
