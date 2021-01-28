#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sliding-window-maximum/
# Author: Miao Zhang
# Date:   2021-01-28

# monotonic queue, keep order, from big num to small num
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        from collections import deque
        res = []
        queue = deque()
        for i in range(len(nums)):
            # keep k elements
            while queue and queue[0] < i - k + 1:
                queue.popleft()
            # from small to big
            while queue and nums[i] > nums[queue[-1]]:
                queue.pop()
            queue.append(i)
            if i >= k - 1:
                res.append(nums[queue[0]])
        return res
