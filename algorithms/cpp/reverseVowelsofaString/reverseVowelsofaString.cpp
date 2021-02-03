// Source: https://leetcode.com/problems/reverse-vowels-of-a-string/
// Author: Miao Zhang
// Date:   2021-02-03

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            while (!isVowel(s[i]) && i < j) i++;
            while (!isVowel(s[j]) && i < j) j--;
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
    
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};
