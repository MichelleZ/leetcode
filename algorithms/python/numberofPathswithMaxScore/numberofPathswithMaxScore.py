#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-paths-with-max-score/
# Author: Miao Zhang
# Date:   2021-04-22

class Solution:
    def pathsWithMaxScore(self, board: List[str]) -> List[int]:
        kMod = 10 ** 9 + 7
        n = len(board)
        dp = [[0 for _ in range(n)] for _ in range(n)]
        cnt = [[0 for _ in range(n)] for _ in range(n)]
        cnt[n - 1][n - 1] = 1
        for i in range(n - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if board[i][j] == 'X': continue
                m = 0
                if i + 1 < n and j + 1 < n:
                    m = dp[i + 1][j + 1]
                if i + 1 < n:
                    m = max(m, dp[i + 1][j])
                if j + 1 < n:
                    m = max(m, dp[i][j + 1])
                dp[i][j] = m + (int(board[i][j]) if board[i][j] != 'S' and board[i][j] != 'E' else 0)
                if i + 1 < n and j + 1 < n and dp[i + 1][j + 1] == m:
                    cnt[i][j] = (cnt[i][j] + cnt[i + 1][j + 1]) % kMod
                if i + 1 < n and dp[i + 1][j] == m:
                    cnt[i][j] = (cnt[i][j] + cnt[i + 1][j]) % kMod
                if j + 1 < n and  dp[i][j + 1] == m:
                    cnt[i][j] = (cnt[i][j] + cnt[i][j + 1]) % kMod
        return [dp[0][0] if cnt[0][0] else 0, cnt[0][0]] 
