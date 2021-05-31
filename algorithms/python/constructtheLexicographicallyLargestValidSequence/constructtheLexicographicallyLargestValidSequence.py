#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/
# Author: Miao Zhang
# Date:   2021-05-31

class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        l = 2 * n - 1
        res = [0] * l
        def dfs(i, s):
            if i == l: return True
            if res[i]:
                return dfs(i + 1, s)
            for d in range(n, 0, -1):
                j = i + (0 if d == 1 else d)
                if (s & (1 << d)) or j >= l or res[j]:
                    continue
                res[i] = res[j] = d
                if dfs(i + 1, s | (1 << d)): 
                    return True
                res[i] = res[j] = 0
            return False
        dfs(0, 0)
        return res
