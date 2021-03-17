// Source: https://leetcode.com/problems/guess-the-word/
// Author: Miao Zhang
// Date:   2021-03-17

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for (int i = 0, cnt = 0; i < 10 && cnt < 6; i++) {
            string guess = wordlist[rand() % wordlist.size()];
            cnt = master.guess(guess);
            vector<string> words;
            for (string& w: wordlist) {
                if (match(guess, w) == cnt) {
                    words.push_back(w);
                }
            }
            wordlist = words;
        }
    }

    int match(string& a, string& b) {
        int res = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i]) res++;
        }
        return res;
    }
};
