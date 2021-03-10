#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/letter-case-permutation/
# Author: Miao Zhang
# Date:   2021-03-10

class Solution:
    def letterCasePermutation(self, S: str) -> List[str]:
        res = []
        
        def dfs(S, i, n):
            if i == n:
                res.append(''.join(S))
                return
            
            dfs(S, i + 1, n)
            if not S[i].isalpha(): return
            S[i] = chr(ord(S[i]) ^ (1 << 5))
            dfs(S, i + 1, n)
            S[i] = chr(ord(S[i]) ^ (1 << 5))
        
        dfs(list(S), 0, len(S))
        return res
