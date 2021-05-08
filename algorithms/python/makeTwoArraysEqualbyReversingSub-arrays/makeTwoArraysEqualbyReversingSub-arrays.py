#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/
# Author: Miao Zhang
# Date:   2021-05-08

class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        t = collections.Counter(target)
        a = collections.Counter(arr)
        return t == a
