// Source: https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/
// Author: Miao Zhang
// Date:   2021-04-15

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> res;
        unordered_map<int, int> freq;
        for (const string& word: words) {
            int mask = 0;
            for (char c: word) {
                mask |= 1 << (c - 'a');
            }
            freq[mask]++;
        }

        for (const string& p: puzzles) {
            int mask = 0;
            for (char c: p) {
                mask |= 1 << (c - 'a');
            }
            int firstcapital = p[0] - 'a';
            int cur = mask;
            int total = 0;
            while (cur) {
                if ((cur >> firstcapital) & 1) {
                    auto it = freq.find(cur);
                    if (it != freq.end())
                        total += it->second;
                }
                cur = (cur - 1) & mask;
            }
            res.push_back(total);
        }
        return res;
    }
};
