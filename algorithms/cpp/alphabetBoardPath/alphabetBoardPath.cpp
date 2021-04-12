// Source: https://leetcode.com/problems/alphabet-board-path/
// Author: Miao Zhang
// Date:   2021-04-12

class Solution {
public:
    string alphabetBoardPath(string target) {
        vector<vector<string>> paths(26, vector<string>(26));
        for (int s = 0; s < 26; s++) {
            for (int t = 0; t < 26; t++) {
                int dx = t / 5 - s / 5;
                int dy = t % 5 - s % 5;
                string path;
                while (dx < 0) {
                    path.push_back('U');
                    dx++;
                }
                while (dy < 0) {
                    path.push_back('L');
                    dy++;
                }
                while (dx > 0) {
                    path.push_back('D');
                    dx--;
                }
                while (dy > 0) {
                    path.push_back('R');
                    dy--;
                }
                paths[s][t] = path;
            }
        }

        char s = 'a';
        string res;
        for (char c: target) {
            res += paths[s - 'a'][c - 'a'] + "!";
            s = c;
        }
        return res;
    }
};
