#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/positions-of-large-groups/
# Author: Miao Zhang
# Date:   2021-03-15

class Solution:
    def largeGroupPositions(self, s: str) -> List[List[int]]:
        res = []
        start = 0
        for i in range(1, len(s) + 1):
            if i == len(s) or s[i] != s[i - 1]:
                if i - start >= 3:
                    res.append([start, i - 1])
                start = i
        return res
        
