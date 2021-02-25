#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
# Author: Miao Zhang
# Date:   2021-02-25

class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        vals = []
        k = len(nums)
        for i in range(k):
            for num in nums[i]:
                vals.append((num, i))
        vals.sort()
        l = 0
        r = 0
        dic = collections.defaultdict(int)
        cnt = 0
        diff = float('inf')
        res = [0, 0]
        for r in range(len(vals)):
            if dic[vals[r][1]] == 0: cnt += 1
            dic[vals[r][1]] += 1
            while cnt == k and l <= r:
                if vals[r][0] - vals[l][0] < diff:
                    diff = vals[r][0] - vals[l][0]
                    res = [vals[l][0], vals[r][0]]
                dic[vals[l][1]] -= 1
                if dic[vals[l][1]] == 0:
                    cnt -= 1
                l += 1
        return res
