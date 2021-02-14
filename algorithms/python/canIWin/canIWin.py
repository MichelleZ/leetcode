#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/can-i-win/
# Author: Miao Zhang
# Date:   2021-02-14

class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        if maxChoosableInteger >= desiredTotal:
            return True
        nums = [i for i in range(1, maxChoosableInteger + 1)]
        if sum(nums) < desiredTotal:
            return False
        if sum(nums) == desiredTotal and len(nums) % 2 != 0:
            return True
        
        self.visited = {}
        return self.canWin(nums, desiredTotal)
    
    def canWin(self, nums: List[int], target: int) -> bool:
        if nums[-1] >= target:
            return True
        if tuple(nums) in self.visited:
            return self.visited[tuple(nums)]
        
        for i in range(len(nums)):
            if not self.canWin(nums[:i] + nums[i + 1:], target - nums[i]):
                self.visited[tuple(nums)] = True
                return True
        self.visited[tuple(nums)] = False
        return False
