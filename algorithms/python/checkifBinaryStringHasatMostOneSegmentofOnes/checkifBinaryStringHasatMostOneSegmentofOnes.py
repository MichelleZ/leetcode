#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
# Author: Miao Zhang
# Date:   2021-06-08

class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        return '01' not in s
