#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
# Author: Miao Zhang
# Date:   2021-04-27

class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        vowels = 'aeiou'
        idx = {0: -1}
        state = 0
        res = 0
        for i in range(len(s)):
            j = vowels.find(s[i])
            if j >= 0: state ^= 1 << j
            if state not in idx:
                idx[state] = i
            res = max(res, i - idx[state])
        return res
