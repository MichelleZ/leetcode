// Source: https://leetcode.com/problems/distribute-candies-to-people/
// Author: Miao Zhang
// Date:   2021-04-09

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int p = (int)(sqrt(2 * candies + 0.25) - 0.5);
        int remaining = (int)(candies - (p + 1) * p * 0.5);
        int rows = p / num_people, cols = p % num_people;
        vector<int> res(num_people, 0);
        for (int i = 0; i < num_people; i++) {
            res[i] = (i + 1) * rows + (int)(rows * (rows - 1) * 0.5) * num_people;
            if (i < cols) {
                res[i] += i + 1 + rows * num_people;
            }
        }
        res[cols] += remaining;
        return res;
    }
};
