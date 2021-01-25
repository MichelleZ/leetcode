#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/repeated-dna-sequences/
# Author: Miao Zhang
# Date:   2021-01-24

class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        visited = set()
        repeated = set()
        for i in range(len(s)):
            cur = s[i: i + 10]
            if cur in visited:
                repeated.add(cur)
            else:
                visited.add(cur)
        return list(repeated)
