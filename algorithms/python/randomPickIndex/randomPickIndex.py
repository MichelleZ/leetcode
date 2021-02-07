#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/random-pick-index/
# Author: Miao Zhang
# Date:   2021-02-07

class Solution:

    def __init__(self, nums: List[int]):
        self.nums = nums

    def pick(self, target: int) -> int:
        res = []
        for i, num in enumerate(self.nums):
            if num == target:
                res.append(i)
        return res[random.randint(0, len(res) - 1)]


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)
