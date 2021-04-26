#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-students-taking-exam/
# Author: Miao Zhang
# Date:   2021-04-26

class Solution:
    def maxStudents(self, seats: List[List[str]]) -> int:
        m = len(seats)
        n = len(seats[0])
        s = [0 for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(n):
                s[i] |= (seats[i - 1][j] == '.') << j
        dp = [[0 for _ in range(1 << n)] for _ in range(m + 1)]
        for i in range(1, m + 1):
            l = s[i - 1]
            while True:
                c = s[i]
                while True:
                    if not (c & (c >> 1)) and not (l & (c >> 1)) and not (c & (l >> 1)):
                        dp[i][c] = max(dp[i][c], dp[i - 1][l] + bin(c).count('1'))
                    if c == 0: break
                    c = (c - 1) & s[i]
                if l == 0: break
                l = (l - 1) & s[i - 1]
        return max(dp[m])
