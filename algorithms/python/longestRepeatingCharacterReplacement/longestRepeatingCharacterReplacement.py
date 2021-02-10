#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-repeating-character-replacement/
# Author: Miao Zhang
# Date:   2021-02-10

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        from collections import defaultdict
        dic = defaultdict(int)
        left = 0
        max_cnt = 0
        for i in range(len(s)):
            dic[s[i]] += 1
            max_cnt = max(max_cnt, dic[s[i]])
            if i - left + 1 > max_cnt + k:
                dic[s[left]] -= 1
                left += 1
        return len(s) - left
