#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reduce-array-size-to-the-half/
# Author: Miao Zhang
# Date:   2021-04-25

class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        cnt = collections.Counter(arr)
        freq, res = 0, 0
        for k, v in cnt.most_common():
            freq += v
            res += 1
            if freq * 2 >= len(arr):
                break
        return res
