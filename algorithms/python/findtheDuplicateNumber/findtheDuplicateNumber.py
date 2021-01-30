#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-the-duplicate-number/
# Author: Miao Zhang
# Date:   2021-01-30

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        return (sum(nums) - sum(set(nums))) // (len(nums) - len(set(nums)))
