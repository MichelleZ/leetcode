#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-music-playlists/
# Author: Miao Zhang
# Date:   2021-03-24

class Solution:
    def numMusicPlaylists(self, N: int, L: int, K: int) -> int:
        kMod = 10 ** 9 + 7
        dp = [[0 for _ in range(N + 1)] for _ in range(L + 1)]
        dp[0][0] = 1
        for i in range(1, L + 1):
            for j in range(1, min(L, N) + 1):
                dp[i][j] = (dp[i - 1][j - 1] * (N - (j - 1)) +
                            dp[i - 1][j] * max(j - K, 0)) % kMod
        
        return dp[L][N]
        
