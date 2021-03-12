#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/soup-servings/
# Author: Miao Zhang
# Date:   2021-03-12

class Solution:
    def soupServings(self, N: int) -> float:
        if N > 5000: return 1.0
        dic = {}
        
        def prob(A, B):
            ops = [[100, 0], [75, 25], [50, 50], [25, 75]]
            if A <= 0 and B <= 0: return 0.5soup Servings
            if A <= 0: return 1.0
            if B <= 0: return 0.0
            if (A, B) in dic:
                return dic[A, B]
            dic[A, B] = 0.0
            for i in range(4):
                dic[A, B] += 0.25 * prob(A - ops[i][0], B - ops[i][1])
            return dic[A, B]
        
        return prob(N, N)
