#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/occurrences-after-bigram/
# Author: Miao Zhang
# Date:   2021-04-07

class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        words = text.split()
        res = []
        prepre = ''
        pre = ''
        for w in words:
            if prepre == first and pre == second:
                res.append(w)
            prepre = pre
            pre = w
        return res
