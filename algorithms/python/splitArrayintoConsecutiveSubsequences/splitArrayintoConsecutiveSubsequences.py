#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/split-array-into-consecutive-subsequences/
# Author: Miao Zhang
# Date:   2021-02-26

class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        freq = collections.defaultdict(int)
        need = collections.defaultdict(int)
        for num in nums: freq[num] += 1
        for num in nums:
            if freq[num] == 0: continue
            if need[num] > 0:
                need[num] -= 1
                need[num + 1] += 1
            elif freq[num + 1] > 0 and freq[num + 2] > 0:
                freq[num + 1] -= 1
                freq[num + 2] -= 1
                need[num + 3] += 1
            else:
                return False
            freq[num] -= 1
        return True
