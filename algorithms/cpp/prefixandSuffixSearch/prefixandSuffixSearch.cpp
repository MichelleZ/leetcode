// Source: https://leetcode.com/problems/prefix-and-suffix-search/
// Author: Miao Zhang
// Date:   2021-03-06

class Trie {
public:
    Trie(): root_(new TrieNode()) {}

    void insert(const string& word, int index) {
        TrieNode* p = root_.get();
        for (auto& c: word) {
            if (!p->children[c - 'a'])
                p->children[c - 'a'] = new TrieNode();
            p = p->children[c - 'a'];
            p->index = index;
        }
        p->is_word = true;
    }

    int startswith(const string& prefix) const {
        auto node = find(prefix);
        if (!node) return -1;
        return node->index;
    }

private:
    struct TrieNode {
        int index;
        int is_word;
        vector<TrieNode*> children;

        TrieNode(): index(-1), is_word(false), children(27, nullptr) {}
        ~TrieNode() {
            for (TrieNode* child: children) {
                if (child) delete child;
            }
        }
    };

    const TrieNode* find(const string& prefix) const {
        const TrieNode* p = root_.get();
        for (const char c: prefix) {
            p = p->children[c - 'a'];
            if (p == nullptr) break;
        }
        return p;
    }

    std::unique_ptr<TrieNode> root_;
};


class WordFilter {
public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            string w = words[i];
            string key = "{" + w;
            trie_.insert(key, i);
            for (int j = 0; j < w.size(); j++) {
                key = w[w.size() - j - 1] + key;
                trie_.insert(key, i);
            }
        }
    }

    int f(string prefix, string suffix) {
        return trie_.startswith(suffix + "{" + prefix);
    }

private:
    Trie trie_;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
