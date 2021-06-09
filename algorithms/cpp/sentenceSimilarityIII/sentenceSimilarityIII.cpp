// Source: https://leetcode.com/problems/sentence-similarity-iii/
// Author: Miao Zhang
// Date:   2021-06-09

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        auto getWords = [] (string& s) {
            stringstream ss(s);
            deque<string> words;
            while (ss) {
                words.emplace_back("");
                ss >> words.back();
            }
            return words;
        };

        deque<string> w1 = getWords(sentence1), w2 = getWords(sentence2);
        while (w1.size() && w2.size() && w1.front() == w2.front()) {
            w1.pop_front();
            w2.pop_front();
        }
        while (w1.size() && w2.size() && w1.back() == w2.back()) {
            w1.pop_back();
            w2.pop_back();
        }
        return w1.empty() || w2.empty();
    }
};
