#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/merge-strings-alternately/
# Author: Miao Zhang
# Date:   2021-06-04

class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        res = ''
        w1, w2 = len(word1), len(word2)
        i, j = 0, 0
        while i < w1 and j < w2:
            res += word1[i]
            res += word2[j]
            i += 1
            j += 1
        if i < w1: res += word1[i:]
        if j < w2: res += word2[j:]
        return res
