#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-ways-to-make-array-with-product/
# Author: Miao Zhang
# Date:   2021-06-02

class Solution:
    def waysToFillArray(self, queries: List[List[int]]) -> List[int]:
        kMod = 10 ** 9 + 7
        n = 0
        c = collections.defaultdict(int)
        dp = collections.defaultdict(int)
        
        def comb(m, k):
            if k > n: return 0
            if k == 0 or k == m: return 1
            if c[(m << 16) | k]:
                return c[(m << 16) | k]
            res = (comb(m - 1, k - 1) + comb(m - 1, k)) % kMod
            c[(m << 16) | k] = res
            return res
        
        def dfs(s, k):
            if s == 0:
                return 1 if k == 1 else 0
            if k == 1:
                return comb(n, s)
            if dp[(s << 16) | k]:
                return dp[(s << 16) | k]
            i = 1
            res = 0
            while i * i <= k:
                if k % i: continue
                if i != 1:
                    res = (res + dfs(s - 1, k // i)) % kMod
                if i * i != k:
                    res = (res + dfs(s - 1, i)) % kMod
                i += 1
            dp[(s << 16) | k] = res 
            return res
        
        ans = []
        for q in queries:
            dp.clear()
            n = q[0]
            ans.append(dfs(n, q[1]))
        return ans
                
