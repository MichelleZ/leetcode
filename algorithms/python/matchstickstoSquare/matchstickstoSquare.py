#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/matchsticks-to-square/
# Author: Miao Zhang
# Date:   2021-02-14

class Solution:
    def makesquare(self, nums: List[int]) -> bool:
        if len(nums) == 0: return False
        sums = 0
        for n in nums: sums += n
        if sums % 4 != 0: return False
        nums.sort()
        visited = [False] * len(nums)
        return self.dfs(nums, 0, sums // 4, 0, 1, visited)
    
    def dfs(self, nums: List[int], pos: int, target: int, tmpSum: int, groupId: int, visited: List[bool]) -> bool:
        if groupId == 4: return True
        if tmpSum == target: 
            return self.dfs(nums, 0, target, 0, groupId + 1, visited)
        if tmpSum > target: return False
        for i in range(pos, len(nums)):
            if visited[i]: continue
            if i > 0 and nums[i] == nums[i - 1] and not visited[i - 1]:
                continue
            visited[i] = True
            if self.dfs(nums, i + 1, target, tmpSum + nums[i], groupId, visited):
                return True
            visited[i] = False
        return False
