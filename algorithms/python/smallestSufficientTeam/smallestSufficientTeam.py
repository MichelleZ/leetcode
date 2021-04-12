#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/smallest-sufficient-team/
# Author: Miao Zhang
# Date:   2021-04-12

class Solution:
    def smallestSufficientTeam(self, req_skills: List[str], people: List[List[str]]) -> List[int]:
        n = len(req_skills)
        target = (1 << n) - 1
        
        skills = []
        for p in people:
            mask = 0
            for s in p:
                mask |= 1 << req_skills.index(s)
            skills.append(mask)
        
        dp = [float('inf') for _ in range(1 << n)]
        parent = [[0, 0] for _ in range(1 << n)]
        dp[0] = 0
        for i in range(len(people)):
            k = skills[i]
            if k == 0: continue
            for j in range(target, -1, -1):
                if dp[j] + 1 < dp[j | k]:
                    dp[j | k] = dp[j] + 1
                    parent[j | k][0] = j
                    parent[j | k][1] = i
        
        t = target
        res = []
        while t:
            res.append(parent[t][1])
            t = parent[t][0]
        return res
