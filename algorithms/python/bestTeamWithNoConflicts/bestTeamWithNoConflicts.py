#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/best-team-with-no-conflicts/
# Author: Miao Zhang
# Date:   2021-05-24

class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        n = len(scores)
        players = []
        for i in range(n):
            players.append([ages[i], scores[i]])
        players.sort(reverse=True)
        dp = [0] * n
        for i in range(n):
            for j in range(i):
                if players[i][1] <= players[j][1]:
                    dp[i] = max(dp[i], dp[j])
            dp[i] += players[i][1]
        return max(dp)
