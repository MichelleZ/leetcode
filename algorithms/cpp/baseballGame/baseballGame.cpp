// Source: https://leetcode.com/problems/baseball-game/
// Author: Miao Zhang
// Date:   2021-03-01

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> nums;
        for (auto& op: ops) {
            if (op == "+") {
                nums.push_back(nums.end()[-1] + nums.end()[-2]);
            } else if (op == "C") {
                nums.pop_back();
            } else if (op == "D") {
                nums.push_back(nums.back() * 2);
            } else {
                nums.push_back(stoi(op));
            }
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};
