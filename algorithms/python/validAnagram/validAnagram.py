#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/valid-anagram/
# Author: Miao Zhang
# Date:   2021-01-28

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        from collections import defaultdict
        dic = defaultdict()
        for ss in s:
            dic[ss] = dic.setdefault(ss, 0) + 1
        for tt in t:
            dic[tt] = dic.setdefault(tt, 0) - 1
        for v in dic.values():
            if v != 0: return False
        return True
