#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sort-characters-by-frequency/
# Author: Miao Zhang
# Date:   2021-02-13

class Solution:
    def frequencySort(self, s: str) -> str:
        from collections import Counter
        res = ''
        counter = Counter(s).most_common()
        for c, v in counter:
            res += c * v
        return res
