// Source: https://leetcode.com/problems/distribute-candies/
// Author: Miao Zhang
// Date:   2021-02-23

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> kinds(candyType.begin(), candyType.end());
        return min(kinds.size(), candyType.size() / 2);
    }
};
