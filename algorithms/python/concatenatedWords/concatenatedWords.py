#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/concatenated-words/
# Author: Miao Zhang
# Date:   2021-02-14

class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        if len(words) <= 2: return [];
        wordset = set(words)
        res = []
        for word in words:
            wordset.remove(word)
            n = len(word)
            if n == 0: continue
            dp = [False] * (n + 1)
            dp[0] = True
            for i in range(n + 1):
                for j in range(i):
                    if dp[j] and word[j: i] in wordset:
                        dp[i] = True
                        break
            if dp[-1]:
                res.append(word)
            wordset.add(word)
        return res
