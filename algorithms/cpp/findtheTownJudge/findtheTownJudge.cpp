// Source: https://leetcode.com/problems/find-the-town-judge/
// Author: Miao Zhang
// Date:   2021-03-31

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> degrees(N + 1);
        for (auto& tr: trust) {
            degrees[tr[0]]--;
            degrees[tr[1]]++;
        }
        for (int i = 1; i < N + 1; i++) {
            if (degrees[i] == N - 1) return i;
        }
        return -1;
    }
};
