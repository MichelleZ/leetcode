#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/4sum/
# Author: Miao Zhang
# Date:   2021-01-06

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        res = []
        for i in range(n - 3):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            for j in range(i + 1, n - 2):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                k = j + 1
                l = n - 1
                while k < l:
                    if nums[k] + nums[l] + nums[i] + nums[j] == target:
                        res.append([nums[i], nums[j], nums[k], nums[l]])
                        k += 1
                        while k < l and nums[k] == nums[k - 1]:
                            k += 1
                        l -= 1
                        while k < l and nums[l] == nums[l + 1]:
                            l -= 1
                    elif nums[k] + nums[l] + nums[i] + nums[j] > target:
                        l -= 1
                    else:
                        k += 1
                    
        return res

