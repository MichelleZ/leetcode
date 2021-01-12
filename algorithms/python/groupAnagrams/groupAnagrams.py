#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/group-anagrams/
# Author: Miao Zhang
# Date:   2021-01-12

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        from collections import defaultdict
        dicts = defaultdict(list)
        for s in strs:
            dicts[''.join(sorted(s))].append(s)
        return dicts.values()
