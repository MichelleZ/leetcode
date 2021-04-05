// Source: https://leetcode.com/problems/stream-of-characters/
// Author: Miao Zhang
// Date:   2021-04-05

class TrieNode {
public:
    ~TrieNode() {
        for (auto node: next_) {
            delete node;
        }
    }

    void reverseBuild(const string&s, int i) {
        if (i == -1) {
            is_word_ = true;
            return;
        }
        const int idx = s[i] - 'a';
        if (!next_[idx]) next_[idx] = new TrieNode();
        next_[idx]->reverseBuild(s, i - 1);
    }

    bool reverseSearch(const string& s, int i) {
        if (i == -1 || is_word_) return is_word_;
        int idx = s[i] - 'a';
        if (!next_[idx]) return false;
        return next_[idx]->reverseSearch(s, i - 1);
    }

private:
    bool is_word_ = false;
    TrieNode* next_[26] = {0};
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        root_ = std::make_unique<TrieNode>();
        for (const string& w: words) {
            root_->reverseBuild(w, w.length() - 1);
        }
    }

    bool query(char letter) {
        s_ += letter;
        return root_->reverseSearch(s_, s_.length() - 1);
    }

private:
    string s_;
    unique_ptr<TrieNode> root_;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
