// Source: https://leetcode.com/problems/goat-latin/
// Author: Miao Zhang
// Date:   2021-03-15

class Solution {
public:
    string toGoatLatin(string S) {
        string vowls = "aeiouAEIOU";
        string res;
        string word;
        int idx = 0;
        istringstream s(S);
        while (s >> word) {
            if (vowls.find(word[0]) == string::npos) {
                word = word.substr(1) + word[0];
            }
            res += " " + word + "ma" + string(++idx, 'a');
        }
        return res.substr(1);
    }
};
