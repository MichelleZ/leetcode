// Source: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
// Author: Miao Zhang
// Date:   2021-05-09

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        for (int i = 0; i < prices.size(); i++) {
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                prices[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        return prices;
    }
};
