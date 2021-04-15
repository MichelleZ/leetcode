// Source: https://leetcode.com/problems/invalid-transactions/
// Author: Miao Zhang
// Date:   2021-04-15

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<bool> invalid(transactions.size(), false);
        vector<vector<string>> trans;
        for (auto t: transactions) {
            string item;
            vector<string> items;
            for (auto c: t) {
                if (c == ',') {
                    items.push_back(item);
                    item = "";
                } else {
                    item += c;
                }
            }
            items.push_back(item);
            trans.push_back(items);
        }
        
        for (int i = 0; i < trans.size(); i++) {
            if (stoi(trans[i][2]) > 1000) invalid[i] = true;
            for (int j = i + 1; j < trans.size(); j++) {
                if ((trans[i][0] == trans[j][0]) && abs(stoi(trans[i][1]) - stoi(trans[j][1])) <= 60 && (trans[i][3] != trans[j][3])) {
                    invalid[i] = true;
                    invalid[j] = true;
                }
            }
        }
        
        vector<string> res;
        for (int i = 0; i < trans.size(); i++) {
            if (invalid[i]) res.push_back(transactions[i]);
        }
        return res;
    }
};
