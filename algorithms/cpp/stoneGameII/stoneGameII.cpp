// Source: https://leetcode.com/problems/stone-game-ii/
// Author: Miao Zhang
// Date:   2021-04-12

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        const int n = piles.size();
        unordered_map<int, int> cache;

        function<int(int, int)> solve = [&](int s, int M) {
            if (s >= n) return 0;
            const int key = (s << 8) | M;
            if (cache.count(key)) return cache[key];
            int best = INT_MIN;
            int curr = 0;
            for (int x = 1; x <= 2 * M; ++x) {
                if (s + x > n) break;
                curr += piles[s + x - 1];
                best = max(best, curr - solve(s + x, max(x, M)));
            }
            return cache[key] = best;
        };
        int total = accumulate(begin(piles), end(piles), 0);
        return  (total + solve(0, 1)) / 2;
    }
};
