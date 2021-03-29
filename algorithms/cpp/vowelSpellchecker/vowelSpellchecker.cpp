// Source: https://leetcode.com/problems/vowel-spellchecker/
// Author: Miao Zhang
// Date:   2021-03-29

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> res;
        unordered_map<string, string> morg;
        unordered_map<string, string> mlow;
        unordered_map<string, string> mvow;
        for (const string& w: wordlist) {
            morg[w] = w;
            string l = toLower(w);
            if (!mlow.count(l)) mlow[l] = w;
            string o = replaceVowels(w);
            if (!mvow.count(o)) mvow[o] = w;
        }
        for (const string& q: queries) {
            if (morg.count(q)) {
                res.push_back(q);
                continue;
            }
            string l = toLower(q);
            if (mlow.count(l)) {
                res.push_back(mlow[l]);
                continue;
            }
            string o = replaceVowels(q);
            if (mvow.count(o)) {
                res.push_back(mvow[o]);
                continue;
            }
            res.push_back("");
        }
        return res;
    }

private:
    string toLower(const string& s) {
        string l(s);
        std::transform(begin(s), end(s), begin(l), ::tolower);
        return l;
    }

    string replaceVowels(const string& s) {
        string o(s);
        std::transform(begin(o), end(o), begin(o), ::tolower);
        for (char& c: o) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                c = '*';
        }
        return o;
    }
};
