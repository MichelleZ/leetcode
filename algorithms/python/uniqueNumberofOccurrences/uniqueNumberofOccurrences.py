#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/unique-number-of-occurrences/
# Author: Miao Zhang
# Date:   2021-04-17

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        cnt = collections.Counter(arr)
        return len(set(cnt.values())) == len(set(arr))
