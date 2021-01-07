// Source: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
// Author: Miao Zhang
// Date:   2021-01-07

/************************************************************************
 * sliding window
 * words_dict == {word: cnt}
 * left is from 0 to s.size - lenOfWord * numsOfWords + 1
 * right is from left to lenOfWord * numsOfWords
 * cur_dict collects the contents from left to right
************************************************************************/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.size() <= 0) {
            return res;
        }
        unordered_map<string, int> words_dict;
        for (auto word: words) {
            if (words_dict.find(word) != words_dict.end()) {
                words_dict[word]++;
            } else {
                words_dict[word] += 1;
            }
        }
        
        int n = s.size(), lenOfWord = words[0].size(), numsOfWords = words.size();
        for (int left = 0; left < n - lenOfWord * numsOfWords + 1; left++) {
            int right = 0;
            unordered_map<string, int> cur_dict;
            
            while (right < numsOfWords) {
                string word = s.substr(left + lenOfWord * right, lenOfWord);
                if (words_dict.find(word) == words_dict.end()) {
                    break;
                }
                if (cur_dict.find(word) != cur_dict.end()) {
                    cur_dict[word]++;
                } else {
                    cur_dict[word] += 1;
                }
                if (cur_dict[word] > words_dict[word]) {
                    break;
                }
                right++;
            }
            
            if (right == numsOfWords) {
                res.push_back(left);
            }
        }
        return res;
    }
};
