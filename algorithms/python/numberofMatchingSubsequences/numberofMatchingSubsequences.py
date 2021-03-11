#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-matching-subsequences/
# Author: Miao Zhang
# Date:   2021-03-11

class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        import bisect
        def isMatch(word: str) -> bool:
            if word in m: return m[word]
            prev = -1
            for c in word:
                index = bisect.bisect_left(pos[c], prev + 1)
                if index == len(pos[c]):
                    m[word] = 0
                    return 0
                prev = pos[c][index]
            m[word] = 1
            return 1
        
        m = {}
        pos = {chr(i + ord('a')) : [] for i in range(26)}
        for i, c in enumerate(s):
            pos[c].append(i)
        return sum(map(isMatch, words))
