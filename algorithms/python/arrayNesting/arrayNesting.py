#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/array-nesting/
# Author: Miao Zhang
# Date:   2021-02-22

class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        res = 0
        visited = [False] * len(nums)
        for i in range(len(nums)):
            cnt = 0
            while not visited[i]:
                cnt += 1
                visited[i] = True
                i = nums[i]
            res = max(res, cnt)
        return res
