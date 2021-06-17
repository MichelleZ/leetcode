#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-number-of-removable-characters/
# Author: Miao Zhang
# Date:   2021-06-16

class Solution:
    def maximumRemovals(self, s: str, p: str, removable: List[int]) -> int:
        ns, np, n = len(s), len(p), len(removable)

        def check(m):
            state = [1] * ns
            for i in range(m):
                state[removable[i]] = 0
            j = 0
            for i in range(ns):
                if state[i] and s[i] == p[j]:
                    j += 1
                    if j == np: return True
            return False

        l, r = 0, n + 1
        while l < r:
            mid = l + (r - l) // 2
            if check(mid):
                l = mid + 1
            else:
                r = mid
        return l - 1
