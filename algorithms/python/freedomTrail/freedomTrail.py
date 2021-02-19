#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/freedom-trail/
# Author: Miao Zhang
# Date:   2021-02-19

class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        '''
        dp[i][pos]: at i-th round, move ring[pos] to 12 o'clock
        dp[i][pos] = min{dp[i - 1][pos'] + dis(pos, pos')}
        '''
        m = len(key)
        n = len(ring)
        
        dic = collections.defaultdict(list)
        for i in range(len(ring)):
            dic[ring[i]].append(i)
        dp = [[float('inf') for _ in range(n)] for _ in range(m)]
        for pos in dic[key[0]]:
            dp[0][pos] = min(dp[0][pos], min(pos, n - pos))
        for i in range(1, m):
            for pos in dic[key[i]]:
                for pre_pos in dic[key[i - 1]]:
                    dp[i][pos] = min(dp[i][pos], dp[i - 1][pre_pos] + min(abs(pos - pre_pos), n - abs(pos - pre_pos)))
        
        res = float('inf')
        for pos in dic[key[m - 1]]:
            res = min(res, dp[m - 1][pos])
        return res + m
