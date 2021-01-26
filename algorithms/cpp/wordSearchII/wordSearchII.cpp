// Source: https://leetcode.com/problems/word-search-ii/
// Author: Miao Zhang
// Date:   2021-01-26

class TrieNode {
public:
    bool is_word;
    vector<TrieNode*> children;
    
    TrieNode(): is_word(false), children(26, nullptr) {
    }
    
    ~TrieNode() {
        for (TrieNode* child: children) {
            if (child) delete child;
        }
    }
};


class TrieTree {
public:
    TrieNode* root_;
    
    TrieTree(): root_(new TrieNode()) {
    }
    
    void insert(string word) {
        TrieNode* p = root_;
        for (auto c: word) {
            if (!p->children[c - 'a']) {
                p->children[c - 'a'] = new TrieNode();
            }
            p = p->children[c - 'a'];
        }
        p->is_word = true;
    }
};


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        TrieTree* trie = new TrieTree();
        TrieNode* node = trie->root_;
        vector<string> res;
        if (words.empty()) return res;
        for (auto word: words) {
            trie->insert(word);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, node, i, j, "", res);
            }
        }
        return res;
    }
    
    void dfs(vector<vector<char>>& board, TrieNode* node, 
             int i, int j, string path, vector<string>& res) {
        if (node->is_word) {
            res.push_back(path);
            node->is_word = false;
        }
        
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '#') return;
        
        char tmp = board[i][j];
        node = (node->children[tmp - 'a'] != nullptr) ? node->children[tmp - 'a'] : nullptr;
        if (node == nullptr) return;
        
        board[i][j] = '#';
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto d: dirs) {
            dfs(board, node, i + d[0], j + d[1], path + tmp, res);
        }
        board[i][j] = tmp;
    }
};
