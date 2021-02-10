#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reconstruct-original-digits-from-english/
# Author: Miao Zhang
# Date:   2021-02-10

class Solution:
    def originalDigits(self, s: str) -> str:
        res = ''
        counts = collections.defaultdict(int)
        for c in s:
            counts[c] += 1
        nums = [0] * 10
        nums[0] = counts['z'];
        nums[2] = counts['w'];
        nums[4] = counts['u'];
        nums[6] = counts['x'];
        nums[8] = counts['g'];
        nums[1] = counts['o'] - nums[0] - nums[2] - nums[4];
        nums[3] = counts['h'] - nums[8];
        nums[5] = counts['f'] - nums[4];
        nums[7] = counts['s'] - nums[6];
        nums[9] = counts['i'] - nums[6] - nums[8] - nums[5];
        for i in range(len(nums)):
            for j in range(nums[i]):
                res += str(i)
        return res
