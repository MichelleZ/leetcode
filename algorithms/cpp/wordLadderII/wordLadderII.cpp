// Source: https://leetcode.com/problems/word-ladder-ii/
// Author: Miao Zhang
// Date:   2021-01-20

class Solution {
public:
    vector<vector<string>> res;
    
    void dfs(string& beginWord, string& endWord, unordered_map<string, unordered_set<string>>& adj, vector<string>& path) {
        if (beginWord == endWord) {
            path.push_back(beginWord);
            res.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(beginWord);
        for (auto w: adj[beginWord]) {
            dfs(w, endWord, adj, path);
        }
        
        path.pop_back();
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, unordered_set<string>> adj;
        unordered_set<string> wordset(wordList.begin(), wordList.end());
        
        queue<string> q;
        q.push(beginWord);
        unordered_map<string, int> visited;
        visited[beginWord] = 0;
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            string newword = word;
            for (int i = 0; i < word.size(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (newword[i] == c) continue;
                    newword[i] = c;
                    if (wordset.count(newword) > 0) {
                        if (visited.count(newword) == 0) {
                            visited[newword] = visited[word] + 1;
                            q.push(newword);
                            adj[word].insert(newword);
                        } else if (visited[newword] == visited[word] + 1) {
                            adj[word].insert(newword);
                        }
                    }
                }
                newword[i] = word[i];
            }
        }
        
        vector<string> path;
        dfs(beginWord, endWord, adj, path);
        return res;
    }
};
