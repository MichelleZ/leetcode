#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/largest-plus-sign/
# Author: Miao Zhang
# Date:   2021-03-08

class Solution:
    def orderOfLargestPlusSign(self, N: int, mines: List[List[int]]) -> int:
        banned = {tuple(mine) for mine in mines}
        dp = [[0 for _ in range(N)] for _ in range(N)]
        res = 0
        for i in range(N):
            cnt = 0
            for j in range(N):  # left
                cnt = 0 if (i, j) in banned else cnt + 1
                dp[i][j] = cnt
            
            cnt = 0
            for j in range(N - 1, -1, -1): # right
                cnt = 0 if (i, j) in banned else cnt + 1
                dp[i][j] = min(dp[i][j], cnt)
        
        for j in range(N):
            cnt = 0
            for i in range(N): # up
                cnt = 0 if (i, j) in banned else cnt + 1
                dp[i][j] = min(dp[i][j], cnt)
            
            cnt = 0
            for i in range(N - 1, -1, -1):
                cnt = 0 if (i, j) in banned else cnt + 1
                dp[i][j] = min(dp[i][j], cnt)
                res = max(dp[i][j], res)
        return res
                
