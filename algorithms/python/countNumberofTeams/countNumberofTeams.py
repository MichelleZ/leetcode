#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-number-of-teams/
# Author: Miao Zhang
# Date:   2021-04-29

class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)
        res = 0
        for j in range(n):
            l = 0
            r = 0
            for i in range(j):
                if rating[i] < rating[j]:
                    l += 1
            for k in range(j + 1, n):
                if rating[k] > rating[j]:
                    r += 1
            res += (l * r) + (j - l) * (n - 1 - j - r)
        return res
