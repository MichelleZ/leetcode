#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-subarray-min-product/
# Author: Miao Zhang
# Date:   2021-06-14

class Solution:
    def maxSumMinProduct(self, nums: List[int]) -> int:
        kMod = 10 ** 9 + 7
        n = len(nums)
        left = [0 for _ in range(n)]
        right = [n - 1 for _ in range(n)]
        stack = []
        for i in range(n):
            while stack and nums[stack[-1]] >= nums[i]:
                right[stack[-1]] = i - 1
                stack.pop()
            if stack:
                left[i] = stack[-1] + 1
            stack.append(i)
        sums = [0 for _ in range(n + 1)]
        for i in range(1, n + 1):
            sums[i] = sums[i - 1] + nums[i - 1]
        res = 0
        for i in range(n):
            res = max(res, (sums[right[i] + 1] - sums[left[i]]) * nums[i])
        return res % kMod
        
