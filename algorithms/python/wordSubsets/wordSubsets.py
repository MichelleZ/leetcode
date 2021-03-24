#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/word-subsets/
# Author: Miao Zhang
# Date:   2021-03-24

class Solution:
    def wordSubsets(self, A: List[str], B: List[str]) -> List[str]:
        def count(word):
            res = [0] * 26
            for c in word:
                res[ord(c) - ord('a')] += 1
            return res
        
        comb = [0] * 26
        for b in B:
            for i, c in enumerate(count(b)):
                comb[i] = max(comb[i], c)
        
        res = []
        for a in A:
            if all(x >= y for x, y in zip(count(a), comb)):
                res.append(a)
        return res
