#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-different-integers-in-a-string/
# Author: Miao Zhang
# Date:   2021-06-09

class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        words = re.findall('\d+', word)
        w = [int(x) for x in words]
        return len(set(w))
