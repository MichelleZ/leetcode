#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/
# Author: Miao Zhang
# Date:   2021-06-11

class Solution:
    def longestBeautifulSubstring(self, word: str) -> int:
        n = len(word)
        res = 0
        last = chr(ord('a') - 1)
        l, vowels = 0, 0
        for r in range(n):
            if word[r] < last:
                vowels = (word[r] == 'a')
                l = r
            elif word[r] > last:
                vowels += 1
            if vowels == 5:
                res = max(res, r - l + 1)
            last = word[r]
        return res
