// Source: https://leetcode.com/problems/design-add-and-search-words-data-structure/
// Author: Miao Zhang
// Date:   2021-01-25

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

class WordDictionary {
private:
    std::unique_ptr<TrieNode> root_;
public:
    /** Initialize your data structure here. */
    WordDictionary(): root_(new TrieNode()) {
    }
    
    void addWord(string word) {
        TrieNode* p = root_.get();
        for (auto c: word) {
            if (!p->children[c - 'a']) {
                p->children[c - 'a'] = new TrieNode();
            }
            p = p->children[c - 'a'];
        }
        p->is_word = true;
    }
    
    bool search(string word) {
        TrieNode* p = root_.get();
        return searchWord(word, p, 0);
    }
    
    bool searchWord(string word, TrieNode* p, int i) {
        if (i == word.size()) return p->is_word;
        if (word[i] == '.') {
            for (auto child: p->children) {
                if (child && searchWord(word, child, i + 1)) return true;
            }
            return false;
        } else {
            return p->children[word[i] - 'a'] && searchWord(word, p->children[word[i] - 'a'], i + 1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
