// Source: https://leetcode.com/problems/implement-magic-dictionary/
// Author: Miao Zhang
// Date:   2021-02-28

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        dict_.clear();
    }

    void buildDict(vector<string> dictionary) {
        for (auto& word: dictionary) {
            for (int i = 0; i < word.size(); i++) {
                char c = word[i];
                word[i] = '*';
                dict_[word].insert(c);
                word[i] = c;
            }
        }
    }

    bool search(string searchWord) {
        for (int i = 0; i < searchWord.size(); i++) {
            char c = searchWord[i];
            searchWord[i] = '*';
            if (dict_.count(searchWord)) {
                auto& charset = dict_[searchWord];
                if (!charset.count(c) || charset.size() > 1) return true;
            }
            searchWord[i] = c;
        }
        return false;
    }

private:
    unordered_map<string, unordered_set<char>> dict_;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
