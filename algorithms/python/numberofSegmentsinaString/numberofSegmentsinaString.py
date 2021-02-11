#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-segments-in-a-string/
# Author: Miao Zhang
# Date:   2021-02-11

class Solution:
    def countSegments(self, s: str) -> int:
        return len(s.split())
