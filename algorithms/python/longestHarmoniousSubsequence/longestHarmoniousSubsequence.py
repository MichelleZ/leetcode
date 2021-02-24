#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-harmonious-subsequence/
# Author: Miao Zhang
# Date:   2021-02-24

class Solution:
    def findLHS(self, nums: List[int]) -> int:
        from collections import Counter
        cnt = Counter(nums)
        res = 0
        for n in nums:
            if n + 1 in cnt:
                res = max(res, cnt[n] + cnt[n + 1])
        return res
