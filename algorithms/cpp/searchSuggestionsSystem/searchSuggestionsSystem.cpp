// Source: https://leetcode.com/problems/search-suggestions-system/
// Author: Miao Zhang
// Date:   2021-04-20

class TrieNode {
public:
    vector<TrieNode*> children;
    vector<string> words;

    TrieNode() : children(26, nullptr) {

    }
    ~TrieNode() {
        for (TrieNode* child: children) {
            if (child) {
                delete child;
            }
        }
    }
};


class Trie {
public:
    Trie(): root_(new TrieNode()) {
    }

    void addWord(const string& word) {
        TrieNode* p = root_.get();
        for (char c: word) {
            if (!p->children[c - 'a']) {
                p->children[c - 'a'] = new TrieNode();
            }
            p = p->children[c - 'a'];
            if (p->words.size() < 3) {
                p->words.push_back(word);
            }
        }
    }

    vector<vector<string>> getWords(const string& prefix) {
        vector<vector<string>> res(prefix.size());
        TrieNode* p = root_.get();
        for (int i = 0; i < prefix.size(); i++) {
            char c = prefix[i];
            p = p->children[c - 'a'];
            if (p == nullptr) break;
            for (auto word: p->words) {
                res[i].push_back(word);
            }
        }
        return res;
    }

private:
    std::unique_ptr<TrieNode> root_;
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        std::sort(begin(products), end(products));
        Trie* trie = new Trie();
        for (const string product: products) {
            trie->addWord(product);
        }
        return trie->getWords(searchWord);
    }
};
