#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/
# Author: Miao Zhang
# Date:   2021-04-15

class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        res = []
        freq = collections.defaultdict(int)
        for word in words:
            mask = 0
            for c in word:
                mask |= 1 << (ord(c) - ord('a'))
            freq[mask] += 1
        for p in puzzles:
            mask = 0
            for c in p:
                mask |= 1 << (ord(c) - ord('a'))
            first = ord(p[0]) - ord('a')
            cur = mask
            total = 0
            while cur:
                if (cur >> first) & 1:
                    if cur in freq:
                        total += freq[cur]
                cur = (cur - 1) & mask
            res.append(total)
        return res
