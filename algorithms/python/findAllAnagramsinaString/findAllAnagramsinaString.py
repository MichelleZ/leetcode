#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-all-anagrams-in-a-string/
# Author: Miao Zhang
# Date:   2021-02-11

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        from collections import Counter
        counter = Counter()
        pCounter = Counter(p)
        left = 0
        right = 0
        res = []
        while right < len(s):
            counter[s[right]] += 1
            if right - left + 1 == len(p):
                if counter == pCounter:
                    res.append(left)
                counter[s[left]] -= 1
                if counter[s[left]] == 0:
                    del counter[s[left]]
                left += 1
            right += 1
        return res
