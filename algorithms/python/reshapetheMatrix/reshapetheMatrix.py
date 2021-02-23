#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reshape-the-matrix/
# Author: Miao Zhang
# Date:   2021-02-23

class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        if not nums: return nums
        m = len(nums)
        n = len(nums[0])
        if m * n != r * c: return nums
        res = [[0 for _ in range(c)] for _ in range(r)]
        for i in range(m * n):
            res[i // c][i % c] = nums[i // n][i % n]
        return res
