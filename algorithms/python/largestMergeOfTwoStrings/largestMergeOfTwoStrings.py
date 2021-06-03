#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/largest-merge-of-two-strings/
# Author: Miao Zhang
# Date:   2021-06-03

class Solution:
    def largestMerge(self, word1: str, word2: str) -> str:
        res = ''
        w1 = len(word1)
        w2 = len(word2)
        i, j = 0, 0
        while i < w1 and j < w2:
            if word1[i:] > word2[j:]:
                res += word1[i]
                i += 1
            else:
                res += word2[j]
                j += 1
        res += word1[i:]
        res += word2[j:]
        return res
