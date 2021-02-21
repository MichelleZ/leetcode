#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/remove-boxes/
# Author: Miao Zhang
# Date:   2021-02-21

################################################################
 # dp[i][j][k] = max(dp[i][j - 1][0] + (k + 1) * (k + 1),
 #                   dp[i][p][k + 1] + dp[p + 1][j - 1][0])
 # "ABACA|AAAA" 
 # case 1: dp("ABAC") + score("AAAAA") drop j and the tail.
 # case 2: box[i] == box[r], l <= i < r, try all break points
 # max({dp("A|AAAAA") + dp("BAC")}, {dp("ABA|AAAAA") + dp("C")})
################################################################
class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:
        n = len(boxes)
        memo = [[[0 for _ in range(n)] for _ in range(n)] for _ in range(n)]
        return self.dfs(boxes, 0, n - 1, 0, memo)
    
    def dfs(self, boxes: List[int], i: int, j: int, k: int, memo: List[List[List[int]]]) -> int:
        if i > j: return 0
        if memo[i][j][k] > 0: return memo[i][j][k]
        memo[i][j][k] = self.dfs(boxes, i, j - 1, 0, memo) + (k + 1) * (k + 1)
        for r in range(i, j):
            if boxes[r] == boxes[j]:
                memo[i][j][k] = max(memo[i][j][k], self.dfs(boxes, i, r, k + 1, memo) + self.dfs(boxes, r + 1, j - 1, 0, memo))
        return memo[i][j][k]
