// Source: https://leetcode.com/problems/rabbits-in-forest/
// Author: Miao Zhang
// Date:   2021-03-10

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        unordered_map<int, int> m;
        // x : n
        for (int ans: answers) m[ans]++;
        for (auto ele: m) {
            // n % (x + 1) == 0, n / (x + 1) * (x + 1)
            // n % (x + 1) != 0, (n / (x + 1) + 1) * (x + 1)
            // (n + x) / (x + 1)
            res += (ele.second + ele.first) / (ele.first + 1) * (ele.first + 1);
        }
        return res;
    }
};
