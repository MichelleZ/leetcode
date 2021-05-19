// Source: https://leetcode.com/problems/rearrange-spaces-between-words/
// Author: Miao Zhang
// Date:   2021-05-19

class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> words;
        int spaces = 0;
        string word;
        for (char& c: text) {
            if (c == ' ') {
                spaces++;
                if (word != "") {
                    words.push_back(word);
                    word = "";
                }
            } else {
                word += c;
            }
        }
        if (word != "") {
            words.push_back(word);
        }

        int n = words.size();
        if (n == 1) {
            return words[0] + string(spaces, ' ');
        }
        string res;
        int interval = spaces / (n - 1);
        for (int i = 0; i < n; i++) {
            res += (i != n - 1) ? (words[i] + string(interval, ' ')) : words[i];
        }
        res += string(spaces % (n - 1), ' ');
        return res;
    }
};
