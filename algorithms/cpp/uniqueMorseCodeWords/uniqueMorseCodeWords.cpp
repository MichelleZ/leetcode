// Source: https://leetcode.com/problems/unique-morse-code-words/
// Author: Miao Zhang
// Date:   2021-03-12

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> dic{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        for (auto& word: words) {
            string code;
            for (char c: word) {
                code += dic[c - 'a'];
            }
            s.insert(code);
        }
        return s.size();
    }
};
