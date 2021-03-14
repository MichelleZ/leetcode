#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/short-encoding-of-words/
# Author: Miao Zhang
# Date:   2021-03-14

class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words = sorted([word[::-1] for word in set(words)])
        last = ''
        res = 0
        for word in words + ['']:
            if not word.startswith(last):
                res += len(last) + 1
            last = word
        return res
