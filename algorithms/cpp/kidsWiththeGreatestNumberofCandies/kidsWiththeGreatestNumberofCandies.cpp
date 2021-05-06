// Source: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
// Author: Miao Zhang
// Date:   2021-05-06

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxval = *max_element(begin(candies), end(candies));
        vector<bool> res(candies.size());
        for (int i = 0; i < candies.size(); i++) {
            res[i] = (candies[i] + extraCandies) >= maxval;
        }
        return res;
    }
};
