#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
# Author: Miao Zhang
# Date:   2021-06-04

class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        res = [0] * n
        cnt = 0
        s = 0
        # left contain self
        for i in range(n):
            res[i] += cnt
            s += int(boxes[i])
            cnt += s
        cnt = 0
        s = 0
        # right
        for i in range(n - 1, -1, -1):
            res[i] += cnt
            s += int(boxes[i])
            cnt += s
        return res
