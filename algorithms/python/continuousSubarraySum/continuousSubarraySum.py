#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/continuous-subarray-sum/
# Author: Miao Zhang
# Date:   2021-02-20

class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        dic = {}
        dic[0] = -1
        sums = 0
        for i in range(len(nums)):
            sums += nums[i]
            if k != 0: sums %= k
            if sums in dic:
                if i - dic[sums] > 1:
                    return True
            else:
                dic[sums] = i
        return False
