// Source: https://leetcode.com/problems/bulls-and-cows/
// Author: Miao Zhang
// Date:   2021-01-31

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        unordered_map<char, int> dic;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) bulls++;
            else {
                dic[secret[i]] += 1;
            }
        }
        for (int i = 0; i < guess.size(); i++) {
            if (secret[i] != guess[i] && dic.find(guess[i]) != dic.end() && dic[guess[i]] != 0) {
                cows++;
                dic[guess[i]] -= 1;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
