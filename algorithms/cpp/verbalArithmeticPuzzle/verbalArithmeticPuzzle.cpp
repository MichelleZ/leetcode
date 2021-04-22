// Source: https://leetcode.com/problems/verbal-arithmetic-puzzle/
// Author: Miao Zhang
// Date:   2021-04-22

class Solution {
public:
    bool isSolvable(vector<string>& words, string result) {
        chars = vector<int>(128, -1);
        visited = vector<int>(10, 0);
        reverse(begin(result), end(result));
        for (auto& word: words) {
            if (word.size() > result.size()) {
                return false;
            }
            reverse(begin(word), end(word));
        }
        return dfs(words, result, 0, 0, 0);
    }

private:
    vector<int> chars;
    vector<int> visited;

    bool dfs(vector<string>& words, string& result, int i, int j, int sums) {
        if (j == result.size()) {
            if (sums != 0) return false;
            if (result.size() > 1 && chars[result.back()] == 0) return false;
            return true;
        }
        if (i == words.size()) {
            char ch = result[j];
            if (chars[ch] != -1) {
                if (chars[ch] != sums % 10) {
                    return false;
                }
                return dfs(words, result, 0, j + 1, sums / 10);
            } else {
                if (visited[sums % 10] == 1)
                    return false;
                chars[ch] = sums % 10;
                visited[sums % 10] = 1;
                if (dfs(words, result, 0, j + 1, sums /10))
                    return true;
                chars[ch] = -1;
                visited[sums % 10] = 0;
                return false;
            }
        }
        if (j >= words[i].size()) {
            return dfs(words, result, i + 1, j, sums);
        }
        char ch = words[i][j];
        if (chars[ch] != -1) {
            if (words[i].size() > 1 && j == words[i].size() - 1 && chars[ch] == 0)
                return false;
            return dfs(words, result, i + 1, j, sums + chars[ch]);
        } else {
            for (int d = 0; d <= 9; d++) {
                if (visited[d] == 1) continue;
                if (d == 0 && j == words[i].size() - 1 && words[i].size() > 1)
                    continue;
                chars[ch] = d;
                visited[d] = 1;
                if (dfs(words, result, i + 1, j, sums + d))
                    return true;
                chars[ch] = -1;
                visited[d] = 0;
            }
            return false;
        }
        return true;
    }
};
