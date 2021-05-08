// Source: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
// Author: Miao Zhang
// Date:   2021-05-08

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size();
        int l = searchWord.size();
        int word = 0;
        for (int i = 0; i < n - l + 1; i++) {
            if (i == 0 || sentence[i - 1] == ' ' ) {
                word++;
                bool valid = true;
                for (int j = 0; j < l && valid; j++) {
                    valid = valid && (sentence[i + j] == searchWord[j]);
                }
                if (valid) return word;
            }
        }
        return -1;
    }
};
