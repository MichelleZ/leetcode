// Source: https://leetcode.com/problems/jewels-and-stones/
// Author: Miao Zhang
// Date:   2021-03-09

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        std::set<char> j(jewels.begin(), jewels.end());
        return std::count_if(stones.begin(), stones.end(), 
                             [&j](const char c) {
                                 return j.count(c);
                             });
    }
};
