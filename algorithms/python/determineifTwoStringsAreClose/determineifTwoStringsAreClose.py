#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/determine-if-two-strings-are-close/
# Author: Miao Zhang
# Date:   2021-05-26

class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        cnt1 = collections.Counter(word1)
        cnt2 = collections.Counter(word2)
        return all([len(word1) == len(word2),
                    cnt1.keys() == cnt2.keys(),
                    sorted(cnt1.values()) == sorted(cnt2.values())])
