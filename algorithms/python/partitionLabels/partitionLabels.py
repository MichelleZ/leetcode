#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/partition-labels/
# Author: Miao Zhang
# Date:   2021-03-08

class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        last_index = {}
        for i, ch in enumerate(S):
            last_index[ch] = i
        start = end = 0
        res = []
        for i, ch in enumerate(S):
            end = max(end, last_index[ch])
            if i == end:
                res.append(end - start + 1)
                start = end + 1
        return res
