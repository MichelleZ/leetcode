#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/circular-array-loop/
# Author: Miao Zhang
# Date:   2021-02-13

class Solution:
    def circularArrayLoop(self, nums: List[int]) -> bool:
        n = len(nums)
        for i in range(n):
            slow = i
            fast = self.getNext(nums, i)
            while nums[fast] * nums[i] > 0 and nums[self.getNext(nums, fast)] * nums[i] > 0:
                if fast == slow:
                    if slow == self.getNext(nums, slow): break
                    return True
                slow = self.getNext(nums, slow)
                fast = self.getNext(nums, self.getNext(nums, fast))
        return False
    
    def getNext(self, nums: List[int], index):
        n = len(nums)
        return (index + nums[index] + n) % n
