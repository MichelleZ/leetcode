#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/similar-string-groups/
# Author: Miao Zhang
# Date:   2021-03-17

class Solution:
    def numSimilarGroups(self, strs: List[str]) -> int:
        res = 0
        visited = set()
        for s in strs:
            if s in visited: continue
            res += 1
            self.dfs(strs, s, visited)
        return res
    
    def dfs(self, strs: List[str], s: str, visited: set) -> None:
        if s in visited: return
        visited.add(s)
        for word in strs:
            if self.isSimilar(word, s):
                self.dfs(strs, word, visited)
    
    def isSimilar(self, word1: str, word2: str) -> bool:
        diff = 0
        for i in range(len(word1)):
            if word1[i] != word2[i]:
                diff += 1
                if diff > 2: return False
        return True
