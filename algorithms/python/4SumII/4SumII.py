#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/4sum-ii/
# Author: Miao Zhang
# Date:   2021-02-13

class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        from collections import Counter
        counter = Counter([a + b for a in A for b in B])
        return sum(counter[-c-d] for c in C for d in D)
