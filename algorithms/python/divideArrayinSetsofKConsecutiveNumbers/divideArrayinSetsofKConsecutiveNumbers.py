#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
# Author: Miao Zhang
# Date:   2021-04-21

class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        m = collections.Counter(nums)
        q = collections.deque(sorted(m))
        while q:
            num = q[0]
            for i in range(k):
                if num + i not in m:
                    return False
                m[num + i] -= 1
                if m[num + i] == 0:
                    q.popleft()
        return True
