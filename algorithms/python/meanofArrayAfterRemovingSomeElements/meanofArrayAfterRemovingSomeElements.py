#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/mean-of-array-after-removing-some-elements/
# Author: Miao Zhang
# Date:   2021-05-21

class Solution:
    def trimMean(self, arr: List[int]) -> float:
        arr.sort()
        offset = len(arr) // 20
        return sum(arr[offset: len(arr) - offset]) / (len(arr) - 2 * offset)
