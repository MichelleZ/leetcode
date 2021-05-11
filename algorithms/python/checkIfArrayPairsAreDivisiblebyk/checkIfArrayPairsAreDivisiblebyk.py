#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
# Author: Miao Zhang
# Date:   2021-05-11

class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        mod = [0] * k
        for a in arr:
            mod[a % k] += 1
        for i in range(1, k):
            if mod[i] != mod[k - i]:
                return False
        return mod[0] % 2 == 0
