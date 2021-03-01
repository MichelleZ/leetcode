#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/
# Author: Miao Zhang
# Date:   2021-03-01

class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        kintervals = [0 for _ in range(n - k + 1)]

        sums = 0
        for i in range(n):
            sums += nums[i]
            if i >= k: sums -= nums[i - k]
            if i >= k - 1: kintervals[i - k + 1] = sums

        left = [0 for _ in range(len(kintervals))]
        best = 0
        for i in range(len(kintervals)):
            if kintervals[i] > kintervals[best]: best = i
            left[i] = best

        right = [0 for _ in range(len(kintervals))]
        best = len(kintervals) - 1
        for i in range(len(kintervals) - 1, -1, -1):
            if kintervals[i] >= kintervals[best]: best = i
            right[i] = best

        res = [-1, -1, -1]
        for j in range(k, len(kintervals) - k):
            i = left[j - k]
            m = right[j + k]
            if res[0] == -1 or kintervals[i] + kintervals[j] + kintervals[m] > kintervals[res[0]] + kintervals[res[1]] + kintervals[res[2]]:
                res[0] = i
                res[1] = j
                res[2] = m
        return res
