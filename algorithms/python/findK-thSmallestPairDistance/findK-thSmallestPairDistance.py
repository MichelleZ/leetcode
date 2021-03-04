#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-k-th-smallest-pair-distance/
# Author: Miao Zhang
# Date:   2021-03-03

class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        nums.sort()
        l = 0
        r = nums[-1] - nums[0]
        while l <= r:
            mid = l + (r - l) // 2
            if self.counter(nums, mid, k):
                r = mid - 1
            else:
                l = mid + 1
        return l

    def counter(self, nums: List[int], mid: int, k: int) -> bool:
        cnt = left = 0
        for right, n in enumerate(nums):
            while n - nums[left] > mid:
                left += 1
            cnt += right - left
        return cnt >= k
