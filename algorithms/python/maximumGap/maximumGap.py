#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-gap/
# Author: Miao Zhang
# Date:   2021-01-24

class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        max_gap = 0
        if not nums or len(nums) < 2: 
            return max_gap
        maxval = max(nums)
        minval = min(nums)
        
        each_bucket_len = (maxval - minval) // len(nums) + 1
        buckets = [[] for _ in range((maxval - minval) // each_bucket_len + 1)]
        for num in nums:
            location = (num - minval) // each_bucket_len
            buckets[location].append(num)
        
        pre_max = float('inf')
        for bucket in buckets:
            if bucket and pre_max != float('inf'):
                max_gap = max(max_gap, min(bucket) - pre_max)
            if bucket:
                pre_max = max(bucket)
        
        return max_gap
