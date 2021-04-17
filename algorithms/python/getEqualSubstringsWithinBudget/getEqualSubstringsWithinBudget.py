#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/get-equal-substrings-within-budget/
# Author: Miao Zhang
# Date:   2021-04-17

class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        res = 0
        left = 0
        right = 0
        cost = 0
        while right < len(s):
            cost += abs(ord(s[right]) - ord(t[right]))
            while left <= right and cost > maxCost:
                cost -= abs(ord(s[left]) - ord(t[left]))
                left += 1
            if cost <= maxCost:
                res = max(res, right - left + 1)
            right += 1
        return res
