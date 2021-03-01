// Source: https://leetcode.com/problems/24-game/
// Author: Miao Zhang
// Date:   2021-03-01

class Solution {
public:
    double EPS = 1e-6;
    int TARGET = 24;
    int ADD = 0, MULTIPLY = 1, SUBTRACT = 2, DIVIDE = 3;

    bool judgePoint24(vector<int>& nums) {
        vector<double> num(nums.begin(), nums.end());
        return solve(num);
    }

private:
    bool solve(vector<double>& nums) {
        if (nums.size() == 0) return false;
        if (nums.size() == 1) return abs(nums[0] - TARGET) < EPS;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) continue;
                vector<double> t;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) t.push_back(nums[k]);
                }
                for (int op = 0; op < 4; op++) {
                    if (op < 2 && i > j) continue;
                    if (op == ADD) {
                        t.emplace_back(nums[i] + nums[j]);
                    } else if (op == MULTIPLY) {
                        t.emplace_back(nums[i] * nums[j]);
                    } else if (op == SUBTRACT) {
                        t.emplace_back(nums[i] - nums[j]);
                    } else if (op == DIVIDE) {
                        if (fabs(nums[j]) < EPS) {
                            continue;
                        }
                        t.emplace_back(nums[i] / nums[j]);
                    }
                    if (solve(t)) return true;
                    t.pop_back();
                }
            }
        }
        return false;
    }
};
