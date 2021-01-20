// Source: https://leetcode.com/problems/word-ladder/
// Author: Miao Zhang
// Date:   2021-01-20

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> wordset(wordList.begin(), wordList.end());
        string wordsdict = "abcdefghijklmnopqrstuvwxyz";
        deque<pair<string, int>> q;
        q.push_back(make_pair(beginWord, 1));
        while (!q.empty()) {
            pair<string, int> cell = q.front();
            q.pop_front();
            if (cell.first == endWord) {
                return cell.second;
            }
            for (int i = 0; i < cell.first.size(); i++) {
                for (auto c: wordsdict) {
                    string newword = cell.first.substr(0, i) + c + cell.first.substr(i + 1);
                    if (wordset.find(newword) != wordset.end() && newword != cell.first) {
                        wordset.erase(newword);
                        q.push_back(make_pair(newword, cell.second + 1));
                    }
                }
            }
        }
            
        return 0;
    }
};
