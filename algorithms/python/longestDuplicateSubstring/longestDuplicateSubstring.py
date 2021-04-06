#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-duplicate-substring/
# Author: Miao Zhang
# Date:   2021-04-06

class Solution:
    def longestDupSubstring(self, s: str) -> str:
        n = len(s)
        nums = [ord(s[i]) - ord('a') for i in range(n)]

        left = 0
        right = n
        res = -1
        while left < right:
            m = left + (right - left) // 2
            idx = self.rabinKarp(m, n, nums)
            if idx != -1:
                res = idx
                left = m + 1
            else:
                right = m
        return s[res: res + left - 1] if res != -1 else ''

    def rabinKarp(self, m: int, n: int, nums: List[int]) -> int:
        visited = set()
        kMod = 2 ** 64
        a = 131
        h = 0
        for i in range(m):
            h = (h * a + nums[i]) % kMod
        visited.add(h)
        tmp = pow(a, m, kMod)
        for i in range(m, n):
            h = (h * a - nums[i - m] * tmp + nums[i]) % kMod
            if h in visited:
                return i - m + 1
            visited.add(h)
        return -1
