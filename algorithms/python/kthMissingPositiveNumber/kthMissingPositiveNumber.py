#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/kth-missing-positive-number/
# Author: Miao Zhang
# Date:   2021-05-14

class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        s = set(arr)
        for i in range(1, arr[-1] + 1):
            if i not in s:
                k -= 1
            if k == 0:
                return i
        return arr[-1] + k
