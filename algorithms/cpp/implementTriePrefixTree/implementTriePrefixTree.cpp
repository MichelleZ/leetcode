// Source: https://leetcode.com/problems/implement-trie-prefix-tree/
// Author: Miao Zhang
// Date:   2021-01-25

class TrieNode {
public:
    bool is_word;
    vector<TrieNode*> children;
public:
    TrieNode(): is_word(false), children(26, nullptr) {
    }
    ~TrieNode() {
        for (TrieNode* child: children) {
            if (child) delete child;
        }
    }
    
};

class Trie {
private:
    std::unique_ptr<TrieNode> root_;
public:
    /** Initialize your data structure here. */
    Trie(): root_(new TrieNode()) {
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root_.get();
        for (auto c: word) {
            if (!p->children[c - 'a']) {
                p->children[c - 'a'] = new TrieNode();
            }
            p = p->children[c - 'a'];
        }
        p->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = root_.get();
        for (auto c: word) {
            p = p->children[c - 'a'];
            if (p == nullptr) return false;
        }
        return p->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = root_.get();
        for (auto c: prefix) {
            p = p->children[c - 'a'];
            if (p == nullptr) return false;
        }
        return true;
    }
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
