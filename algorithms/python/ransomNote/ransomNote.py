#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/ransom-note/
# Author: Miao Zhang
# Date:   2021-02-06

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        from collections import Counter
        return not Counter(ransomNote) - Counter(magazine)
