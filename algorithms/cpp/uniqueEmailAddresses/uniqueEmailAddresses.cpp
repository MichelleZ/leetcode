// Source: https://leetcode.com/problems/unique-email-addresses/
// Author: Miao Zhang
// Date:   2021-03-26

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> seen;
        for (auto& email: emails) {
            string e;
            bool plus = false;
            bool at = false;
            for (char c: email) {
                if (c == '.') {
                    if (!at) continue;
                } else if (c == '@') {
                    at = true;
                } else if (c == '+') {
                    if (!at) {
                        plus = true;
                        continue;
                    }
                } 
                if (!at && plus) continue;
                e += c;
            }
            seen.insert(std::move(e));
        }
        return seen.size();
    }
};
