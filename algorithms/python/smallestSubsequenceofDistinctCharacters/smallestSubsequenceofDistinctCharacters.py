#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
# Author: Miao Zhang
# Date:   2021-04-07

class Solution:
    def smallestSubsequence(self, s: str) -> str:
        cnt = collections.Counter(s)
        res = []
        visited = set()
        for c in s:
            cnt[c] -= 1
            if c in visited: continue
            while res and c < res[-1] and cnt[res[-1]]:
                visited.remove(res[-1])
                res.pop()
            res.append(c)
            visited.add(c)
        return ''.join(res)
