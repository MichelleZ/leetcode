#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/cracking-the-safe/
# Author: Miao Zhang
# Date:   2021-03-07

class Solution:
    def crackSafe(self, n: int, k: int) -> str:
        visited = set()
        res = []
        
        def dfs(node):
            for edge in list(map(str, range(k))):
                val = node + edge
                if val not in visited:
                    visited.add(val)
                    dfs(val[1:])
                    res.append(edge)
        
        dfs("0" * (n - 1))
        return ''.join(res) + '0' * (n - 1)
