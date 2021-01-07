#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/remove-element/
# Author: Miao Zhang
# Date:   2021-01-07

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        j = 0
        for num in nums:
            if num != val:
                nums[j] = num
                j += 1
        return j
