// Source: https://leetcode.com/problems/shopping-offers/
// Author: Miao Zhang
// Date:   2021-02-25

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int with_offer = INT_MAX;
        for (auto offer: special) {
            vector<int> remain(needs);
            bool valid_offer = true;
            for (int i = 0; i < price.size(); i++) {
                if (!(valid_offer &= ((remain[i] -= offer[i]) >= 0))) break;
            }
            if (!valid_offer) continue;
            with_offer = min(with_offer, shoppingOffers(price, special, remain) + offer.back());
        }
        int without_offer = inner_product(begin(price), end(price), begin(needs), 0);
        return min(with_offer, without_offer);
    }
};
