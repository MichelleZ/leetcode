// Source: https://leetcode.com/problems/incremental-memory-leak/
// Author: Miao Zhang
// Date:   2021-06-14

class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        for (int i = 0; i < 2e30; i++) {
            if (max(memory1, memory2) < i) {
                return {i, memory1, memory2};
            } else if (memory1 >= memory2) {
                memory1 -= i;
            } else {
                memory2 -= i;
            }
        }
        return {};
    }
};
