#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/
# Author: Miao Zhang
# Date:   2021-03-30

class Solution:
    def countTriplets(self, A: List[int]) -> int:
        d = collections.Counter(a & b for a in A for b in A)
        return sum((not a & k) * v for a in A for k, v in d.items())
