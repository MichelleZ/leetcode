#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/print-words-vertically/
# Author: Miao Zhang
# Date:   2021-04-23

class Solution:
    def printVertically(self, s: str) -> List[str]:
        words = s.split()
        maxlen = max(len(word) for word in words) # row
        res = list()
        for i in range(maxlen):
            ss = ''
            for word in words:
                if i < len(word):
                    ss += word[i]
                else:
                    ss += ' '
            res.append(ss.rstrip())
        return res
