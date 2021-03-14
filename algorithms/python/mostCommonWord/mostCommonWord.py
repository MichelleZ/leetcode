#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/most-common-word/
# Author: Miao Zhang
# Date:   2021-03-14

class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        p = ''.join([c.lower() if c.isalnum() else ' ' for c in paragraph])
        words = p.split()
        counter = collections.Counter(words).most_common()
        b = set(banned)
        for c in counter:
            if c[0] not in b:
                return c[0]
