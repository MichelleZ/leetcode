#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/
# Author: Miao Zhang
# Date:   2021-06-17

class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        cnt = [0] * 26
        n = len(words)
        for word in words:
            for c in word:
                cnt[ord(c) - ord('a')] += 1
        return all(k % n == 0 for k in cnt)
