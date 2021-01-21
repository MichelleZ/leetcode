#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/word-break-ii/
# Author: Miao Zhang
# Date:   2021-01-21

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        words = set(wordDict)
        mem = {}
        def wordBreak(s):
            if s in mem: return mem[s]
            res = []
            if s in words: res.append(s)
            for i in range(1, len(s)):
                right = s[i:]
                if right not in words: continue        
                res += [w + " " + right for w in wordBreak(s[0:i])]
            mem[s] = res
            return mem[s]
        return wordBreak(s)
