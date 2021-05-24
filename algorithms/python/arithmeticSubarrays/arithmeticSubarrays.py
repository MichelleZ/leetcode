#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/arithmetic-subarrays/
# Author: Miao Zhang
# Date:   2021-05-24

class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        res = []
        for i in range(len(l)):
            arr = nums[l[i]: r[i] + 1]
            arr.sort()
            d = arr[1] - arr[0]
            for j in range(2, len(arr)):
                if arr[j] - arr[j - 1] != d:
                    res.append(False)
                    break
            else:
                res.append(True)
        return res
