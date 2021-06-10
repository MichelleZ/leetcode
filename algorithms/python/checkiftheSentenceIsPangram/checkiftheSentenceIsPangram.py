#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/check-if-the-sentence-is-pangram/
# Author: Miao Zhang
# Date:   2021-06-10

class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        s = set()
        for c in sentence:
            s.add(c)
        return len(s) == 26
