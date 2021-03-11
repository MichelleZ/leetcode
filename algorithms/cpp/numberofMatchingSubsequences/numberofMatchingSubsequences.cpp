// Source: https://leetcode.com/problems/number-of-matching-subsequences/
// Author: Miao Zhang
// Date:   2021-03-11

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int res = 0;
        unordered_map<string, bool> m;
        for (const string& word: words) {
            auto it = m.find(word);
            if (it == m.end()) {
                bool match = isMatch(word, s);
                res += m[word] = match;
            } else {
                res += it->second;
            }
        }
        return res;
    }

private:
    bool isMatch(const string& word, const string& S) {
        int start = 0;
        for (const char c: word) {
            bool found = false;
            for (int i = start; i < S.length(); i++) {
                if (S[i] == c) {
                    found = true;
                    start = i + 1;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }
};

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> pos(128);
        for (int i = 0; i < s.length(); i++) {
            pos[s[i]].push_back(i);
        }
        int res = 0;
        for (const string& word: words) {
            res += isMatch(word, pos);
        }
        return res;
    }

private:
    unordered_map<string, bool> m_;
    bool isMatch(const string& word, const vector<vector<int>>& pos) {
        if (m_.count(word)) return m_[word];
        int prev = -1;
        for (const char c: word) {
            const vector<int>& p = pos[c];
            const auto it = std::lower_bound(p.begin(), p.end(), prev + 1);
            if (it == p.end()) return m_[word] = false;
            prev = *it;
        }
        return m_[word] = true;
    }
};
