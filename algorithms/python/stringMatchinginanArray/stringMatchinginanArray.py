#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/string-matching-in-an-array/
# Author: Miao Zhang
# Date:   2021-04-30

class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        res = []
        n = len(words)
        for i in range(n):
            for j in range(n):
                if i == j: 
                    continue
                if words[i] in words[j]:
                    res.append(words[i])
                    break
        return res
