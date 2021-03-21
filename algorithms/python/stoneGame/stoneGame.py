#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/stone-game/
# Author: Miao Zhang
# Date:   2021-03-20

class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        n = len(piles)
        dp = [[float('-inf') for _ in range(n)] for _ in range(n)]
        return self.score(piles, 0, n - 1, dp)
    
    def score(self, piles: List[int], l: int, r: int, dp: List[List[int]]) -> int:
        if l == r: return piles[l]
        if dp[l][r] == float('-inf'):
            dp[l][r] = max(piles[l] - self.score(piles, l + 1, r, dp),
                           piles[r] - self.score(piles, l, r - 1, dp))
        return dp[l][r]
