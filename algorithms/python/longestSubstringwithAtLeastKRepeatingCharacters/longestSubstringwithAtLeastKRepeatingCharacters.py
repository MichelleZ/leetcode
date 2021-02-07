#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
# Author: Miao Zhang
# Date:   2021-02-07

class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        if len(s) < k: return 0
        for c in set(s):
            if s.count(c) < k:
                return max(self.longestSubstring(t, k) for t in s.split(c))
        return len(s)
