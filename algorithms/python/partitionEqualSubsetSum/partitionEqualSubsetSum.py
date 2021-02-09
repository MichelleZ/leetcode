#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/partition-equal-subset-sum/
# Author: Miao Zhang
# Date:   2021-02-09

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        sums = sum(nums)
        div, mod = divmod(sums, 2)
        if mod or max(nums) > div: return False
        nums.sort(reverse=True)
        target = [div] * 2
        return self.dfs(nums, 0, target)
    
    def dfs(self, nums: List[int], index: int, target: int) -> bool:
        for i in range(2):
            if target[i] >= nums[index]:
                target[i] -= nums[index]
                if target[i] == 0 or self.dfs(nums, index + 1, target):
                    return True
                target[i] += nums[index]
        return False

############################################################################
class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        sums = sum(nums)
        if sums % 2 != 0: return False
        dp = [0] * (sums + 1)
        dp[0] = 1
        for n in nums:
            # reverse traverse dp
            for i in range(sums, -1, -1):
                if dp[i]:
                    dp[i + n] = 1
            if dp[sums / 2]:
                return True
        return False
