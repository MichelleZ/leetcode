#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/
# Author: Miao Zhang
# Date:   2021-05-05

class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        return max(1, 1 - min(itertools.accumulate(nums)))
