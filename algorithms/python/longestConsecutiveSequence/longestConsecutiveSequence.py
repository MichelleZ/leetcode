#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-consecutive-sequence/
# Author: Miao Zhang
# Date:   2021-01-20

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        record = dict()
        res = 0
        for num in nums:
            if num not in record:
                left = record.get(num - 1, 0)
                right = record.get(num + 1, 0)
                length = left + right + 1
                res = max(res, length)
                for i in [num - left, num, num + right]:
                    record[i] = length
        return res
