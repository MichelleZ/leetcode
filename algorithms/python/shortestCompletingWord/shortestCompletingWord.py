#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/shortest-completing-word/
# Author: Miao Zhang
# Date:   2021-03-06

class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        def count(itera):
            ans = [0] * 26
            for letter in itera:
                ans[ord(letter) - ord('a')] += 1
            return ans

        def matches(c1, c2):
            return all(x1 >= x2 for x1, x2 in zip(c1, c2))

        res = ""
        min_len = float('inf')
        target = count(c.lower() for c in licensePlate if c.isalpha())
        for word in words:
            if len(word) < min_len and matches(count(word.lower()), target):
                res = word
                min_len = len(word)
        return res
