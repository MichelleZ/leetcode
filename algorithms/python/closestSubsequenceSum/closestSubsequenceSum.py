#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/closest-subsequence-sum/
# Author: Miao Zhang
# Date:   2021-06-03

class Solution:
    def minAbsDifference(self, nums: List[int], goal: int) -> int:
        def dfs(i,cur,arr,sums):
            if i==len(arr):
                sums.add(cur)
                return
            dfs(i + 1, cur, arr,sums)
            dfs(i + 1, cur + arr[i], arr, sums)
        
        sums1, sums2 = set(), set()
        dfs(0, 0, nums[: len(nums)//2], sums1)
        dfs(0, 0, nums[len(nums)//2:], sums2)
        
        s2 = sorted(sums2)
        res = abs(goal)
        for s in sums1:
            remain = goal - s
            i2= bisect_left(s2, remain)
            if i2 < len(s2):
                res = min(res,abs(remain-s2[i2]))
            if i2>0:
                res = min(res,abs(remain-s2[i2 - 1]))
        return res
