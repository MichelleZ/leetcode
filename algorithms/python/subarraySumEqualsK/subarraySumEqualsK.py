#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/subarray-sum-equals-k/
# Author: Miao Zhang
# Date:   2021-02-22

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        if not nums: return 0
        cnt = defaultdict(int)
        cnt[0] = 1
        cur_sum = 0
        res = 0
        for n in nums:
            cur_sum += n
            res += cnt[cur_sum - k]
            cnt[cur_sum] += 1
        return res
