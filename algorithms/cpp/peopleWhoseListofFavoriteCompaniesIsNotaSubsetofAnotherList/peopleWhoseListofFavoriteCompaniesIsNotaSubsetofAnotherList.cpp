// Source: https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/
// Author: Miao Zhang
// Date:   2021-05-08

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        vector<int> res;
        for_each(begin(favoriteCompanies), end(favoriteCompanies), [] (vector<string>& vec) {
            sort(begin(vec), end(vec));
        });
        for (int i = 0; i < favoriteCompanies.size(); i++) {
            bool isSubset = false;
            for (int j = 0; j < favoriteCompanies.size(); j++) {
                isSubset = i != j && includes(favoriteCompanies[j].begin(), favoriteCompanies[j].end(), favoriteCompanies[i].begin(), favoriteCompanies[i].end());
                if (isSubset) break;
            }
            if (!isSubset) {
                res.push_back(i);
            }
        }
        return res;
    }
};
