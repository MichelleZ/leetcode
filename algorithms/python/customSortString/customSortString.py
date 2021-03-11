#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/custom-sort-string/
# Author: Miao Zhang
# Date:   2021-03-11

class Solution:
    def customSortString(self, S: str, T: str) -> str:
        return "".join(sorted(T, key=lambda x: S.find(x)))
